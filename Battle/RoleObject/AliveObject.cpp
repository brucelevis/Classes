﻿#include "AliveObject.h"
#include "Battle/AnimationManager.h"
#include "common/CommonFunction.h"
#include "Battle/ConstNum.h"
#include "model/DataCenter.h"
#include "tools/StringUtil.h"
#include "Battle/RoleObject/HPObject.h"
#include "Battle/RoleObject/RageObject.h"
#include "Battle/EffectObject.h"
#include "Global.h"
#include "Battle/BaseRole.h"
#include "Battle/BattleLayer/BattleRoleLayer.h"
#include "model/WarManager.h"
#include "Battle/BaseRoleData.h"
#include "common/CGameSound.h"
#include "common/ShaderDataHelper.h"
#include "Battle/CHeroSoundData.h"
#include "model/BuffManage.h"
#include "Battle/BattleMessage.h"
#include "Battle/MoveObject.h"
#include "Battle/ActionNameDefine.h"

namespace BattleSpace{
	AliveObject::AliveObject()
		:m_Body(nullptr),m_HpObject(nullptr),m_Name(""),m_ActionKey(""),m_MoveState(sStateCode::eNullState)
		,m_NameLabel(nullptr),m_Armature(nullptr),m_DropItem(0),m_offs(CCPointZero)
		,mEnemy(false),m_EffectMusic(0),m_IsSpine(false),m_Speed(CCPointZero)
		,m_Direction(-1),mModel(0),mRole(nullptr),mMoveObj(nullptr)
		,m_AtkEffect(0),m_PlayerEffect(0),m_UpdateState(true),m_Skeleton(nullptr)
	{}
	AliveObject::~AliveObject()
	{
		if(m_HpObject) removeChild(m_HpObject);
		if(m_NameLabel) removeChild(m_NameLabel);
		if(m_Body) removeChild(m_Body);
		CC_SAFE_RELEASE(m_HpObject);
		CC_SAFE_RELEASE(m_NameLabel);
		CC_SAFE_RELEASE(m_Body);
		m_HpObject = nullptr;
		m_NameLabel = nullptr;
		m_Body = nullptr;
	}

	bool AliveObject::init()
	{
		setBody(nullptr);
		return true;
	}

	void AliveObject::setBody(CCSprite* body)
	{
		m_Body = CCSprite::create();
		m_Body->retain();
		this->addChild(m_Body);
	}
	CCSprite* AliveObject::getBody() { return m_Body; }

	void AliveObject::testLabel()
	{
		int tageNumber = 3000;
		CCLabelTTF* AliveID = CCLabelTTF::create(ToString(tageNumber+mRole->getAliveID()),"arial",20);
		AliveID->setColor(ccc3(255,0,0));
		AliveID->setPosition(ccp(0,60));
		CCLabelTTF* AliveMode = CCLabelTTF::create(ToString(mModel),"arial",20);
		AliveMode->setColor(ccc3(255,0,0));
		AliveMode->setPosition(ccp(0,30));
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		this->addChild(AliveMode);
		this->addChild(AliveID);
#endif
	}

	void AliveObject::setHp(HPObject* hp)
	{
		testLabel();
		m_HpObject = HPObject::create();
		m_HpObject->initHp(this);
		m_HpObject->retain();
		m_HpObject->setPosition(ccp(0,-5));
		m_Armature->addChild(m_HpObject, 100);
		initAliveTypeIcon();
	}
	HPObject* AliveObject::getHp() { return m_HpObject; }

	void AliveObject::initTypeIconPath(char* pPath)
	{
		const HeroInfoData *c_data = DataCenter::sharedData()->getHeroInfo()->getCfg(mRole->getBaseData()->getRoleModel());
		if(c_data)
		{
			sprintf(pPath,"common/type_%d_%d.png", mRole->getBaseData()->getProperty(), c_data->iType2);
		}else{
			sprintf(pPath,"common/type_1_1.png");
			CCLOG("[ *ERROR ] AliveObject::initAliveTypeIcon %d",mRole->getBaseData()->getRoleModel());
		}
	}

	void AliveObject::initAliveTypeIcon()
	{
		char tPath[60]={0};								//在外部创建存储空间再传入赋值的写法比较安全
		initTypeIconPath(tPath);
		CCSprite* tTypeIcon = CCSprite::create(tPath);
		if (!tTypeIcon)
		{
			tTypeIcon = CCSprite::create("common/type_1_1.png");
			CCLOG("[ *ERROR ] AliveObject::initAliveTypeIcon %s",tPath);
		}
		tTypeIcon->setScale(0.5f);
		tTypeIcon->setPosition(ccp(-m_HpObject->getContentSize().width/2,0));			//在body处设置了翻转了
		m_HpObject->addChild(tTypeIcon);
	}

	void AliveObject::setNickName(string nickName)//设置武将名字
	{
		if( nickName.c_str() == nullptr || m_Name == nickName ) return;
		m_Name = nickName;
		if(m_NameLabel == nullptr)
		{
			m_NameLabel = CCLabelTTF::create();
			if(m_NameLabel == nullptr) return;
			m_NameLabel->retain();
			m_NameLabel->setFontSize(20);
			m_NameLabel->setFontName("arial");
			m_Body->addChild( m_NameLabel );
		}
		m_NameLabel->setString(m_Name.c_str());
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		m_NameLabel->setVisible(true);
#else
		m_NameLabel->setVisible(false);
#endif
	}
	string AliveObject::getNickName() { return m_Name; }//设置名字颜色

	void AliveObject::setRoleDirection(int direction)//设置人物方向
	{
		m_Direction = direction;
		if (m_IsSpine && DataCenter::sharedData()->getRoleData()->isTurn(mModel))
		{
			if(m_Direction == Ditection_Left)
			{
				if (m_Skeleton)
					m_Skeleton->setScaleX(1);//spine特效
				m_Armature->setScaleX(1);//spine人物
			}else{
				if (m_Skeleton)
					m_Skeleton->setScaleX(-1);//翻转
				m_Armature->setScaleX(-1);//spine人物
			}
		}else{
			if(m_Direction == Ditection_Left)
			{
				if (m_Skeleton)
					m_Skeleton->setScaleX(-1);//spine特效
				m_Armature->setScaleX(-1);//spine人物
			}else{
				if (m_Skeleton)
					m_Skeleton->setScaleX(1);//spine特效
				m_Armature->setScaleX(1);//spine人物
			}
		}
	}
	int AliveObject::getRoleDirection() { return m_Direction; }
	//这个方法不属于数据类，也不属于显示类，但是应该在武将自身的身上，每个武将的死亡处理都不一样。
	void AliveObject::AliveDie()
	{
		mRole->clearHitAlive();
		mRole->setHp(0);
		mRole->setBattle(false);
		mRole->setGridIndex(INVALID_GRID);
		m_HpObject->setHpNumber(0);
		if (mRole->getMoveObject())
			mRole->getMoveObject()->removeFromParentAndCleanup(true);
		mRole->setMoveObject(nullptr);
		this->setMoveObject(nullptr);
		mRole->getBuffManage()->Buffclear();
		NOTIFICATION->postNotification(B_DrpItem,this);
		NOTIFICATION->postNotification(MsgRoleDie,mRole);
	}
	//做受击判断和一个冲锋0号格子特殊处理,攻击音效攻击特效播放,使用了受击数组但是未操作
	void AliveObject::AtkBegin_Event()
	{
		if(m_AtkEffect)
		{
			EffectObject* _Effect = EffectObject::create(ToString(m_AtkEffect));
			this->addChild(_Effect);						//播在人物身上，不会发生偏移，跟着人物走动的
			_Effect->setShaderEffect(m_Armature->getShaderProgram());
		}
		//NOTIFICATION->postNotification(Draw_SKILL_Area,m_Alive);//绘制攻击范围
	}
	//操作受击数组,播完掉血则移除当前回合受击数组
	void AliveObject::HpChange_Event()
	{
		mRole->attackEventLogic();
		//if (getPlayerEffect())
			//NOTIFICATION->postNotification(B_SkilEffectInMap,this);
	}
	//攻击区域必杀技状态才绘制,攻击完毕可以将武将传出去,进行下一个效果的判断或是重置武将信息等
	void AliveObject::AtkEnd_Event()
	{
		if (!m_UpdateState)
			return;
		NOTIFICATION->postNotification(B_CancelDrawAttackArea,mRole);		//取消绘制攻击范围(针对性的取消绘制)
		if (mRole->mAreaTargets.size())
		{
			if (mRole->NextEffect())
			{
				mRole->ExcuteNextEffect();
			}else{
				mRole->ResetAttackState();								//逻辑处理完毕重置武将状态信息
				if (!mRole->getCriAtk()&&!mRole->getSpeAtk())
					mRole->setAtkNum(1);									//普通攻击次数累加
			}	
		}else{
			mRole->ResetAttackState();									//逻辑处理完毕重置武将状态信息
		}																					
	}
	//分解sData//0.动画名称1.scalex2.scaley3.offx4.offy5.offZorder
	void AliveObject::PlayAnimat_Event(string sData)
	{
		CCArray* pArr = strSplit(sData.c_str(), "_");
		string sAnimatName = ((CCString*)pArr->objectAtIndex(0))->m_sString;
		float fScaleX = atof(((CCString*)pArr->objectAtIndex(1))->getCString());
		float fScaleY= atof(((CCString*)pArr->objectAtIndex(2))->getCString());
		int iOffX = atoi(((CCString*)pArr->objectAtIndex(3))->getCString());
		int iOffY = atoi(((CCString*)pArr->objectAtIndex(4))->getCString());
		int iOffZorder = atoi(((CCString*)pArr->objectAtIndex(5))->getCString());

		//获取动画
		EffectObject* pAnimat = EffectObject::create(sAnimatName.c_str());
		pAnimat->setScaleX(fScaleX);
		pAnimat->setScaleX(fScaleY);
		pAnimat->setPosition(m_Armature->getPosition() + ccp(iOffX, iOffY));
		pAnimat->setZOrder(m_Armature->getZOrder()+iOffZorder);
		m_Armature->getParent()->addChild(pAnimat);
		pAnimat->setShaderEffect(m_Armature->getShaderProgram());
	}

	void AliveObject::playerNum( int num,int type )
	{
		if (type == nullType)return;
		if (!num&&type!=typeface)
		{
			CCLOG(" [ Tips ] AliveObject::playerNum Num = 0!");
			return	;
		}
		m_HpObject->playChangeNumber(num,type);
		if (mRole->getMonsterSpecies() == sMonsterSpecies::eWorldBoss)														//boss的情况处理应该在血量条的内部,自己进行。
			NOTIFICATION->postNotification(B_WorldBoss_HurtUpdate,CCInteger::create(m_HpObject->getHpNumber()));	
		if (type > gainType)
			lostHpDispose();
	}

	void AliveObject::lostHpDispose()
	{		//这个函数应该是多余的,在武将创建的时候，应该就经过一次武将的特殊信息初始化，根据配置文件来初始化武将的一些配置的信息，而不是每次武将受击的时候才去找
		CCNode* Effect = DataCenter::sharedData()->getRoleData()->getActionEffect(mRole->getModel());			
		if (Effect)
			this->addChild(Effect);
		m_Armature->runAction(CCSequence::create(
			CCTintTo::create(0.25f,255,0,0),CCTintTo::create(0,255,255,255),NULL));								//变红处理
		if (mRole->getCaptain())
		{
			NOTIFICATION->postNotification(B_CaptainHurt,mRole);
			NOTIFICATION->postNotification(B_Shark,nullptr);
		}
	}

	void AliveObject::showThis()
	{
		this->setVisible(true);
		m_HpObject->showHp(nullptr);
	}

	void AliveObject::countOffs( CCPoint pMapPoint )
	{
		setPosition(pMapPoint);
		if (mRole->getBaseData()->getRoleRow()>1)
		{
			if (mRole->getBaseData()->getRoleRow()>2)
			{
				setPosition(ccpAdd(getPosition(),ccp(0,-GRID_HEIGHT/1.5f*mRole->getBaseData()->getRoleRow())));	
			}else{
				setPosition(ccpAdd(getPosition(),ccp(0,-GRID_HEIGHT/3*mRole->getBaseData()->getRoleRow())));
			}
		}
		if (mRole->getBaseData()->getRoleCol()>1&&!mRole->getCaptain())
			setPosition(ccpAdd(getPosition(),ccp(GRID_WIDTH/4*mRole->getBaseData()->getRoleCol(),0)));
		setoffs(getPosition()-pMapPoint);		//算出武将偏移实际站位格子的偏移量
		monsterSoleSprite();
	}

	void AliveObject::monsterSoleSprite()
	{
		if (!mRole->getEnemy())
			return;
		CCSprite* ef = nullptr;
		for (int i=0;i<mRole->getBaseData()->getRoleRow();i++)
			for (int j =0;j<mRole->getBaseData()->getRoleCol();j++)
			{
				ef = CCSprite::create("warScene/fanglandingwei.png");
				ef->setPosition(ccp(-getoffs().x+(j*(GRID_WIDTH+C_GRIDOFFSET_X)),-getoffs().y-(i*(GRID_HEIGHT+C_GRIDOFFSET_Y))));
				//aliveOb->addChild(ef,-1);
			}
	}

}