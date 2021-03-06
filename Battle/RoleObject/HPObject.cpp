﻿#include "Battle/RoleObject/HPObject.h"
#include "Battle/RoleObject/RoleObject.h"
#include "Battle/WarControl.h"
#include "Battle/ConstNum.h"
#include "Battle/BattleResult.h"
#include "common/CGameSound.h"
#include "common/ShaderDataHelper.h"
#include "Battle/RoleConfig.h"
#include "Battle/BattleMessage.h"
#include "Battle/BaseRole.h"
#include "Battle/RoleObjectMacro.h"
namespace BattleSpace
{
	HPObject::HPObject()
	:m_Skin(nullptr),m_Background(nullptr),m_HpNumber(0),m_HpNumberMax(0),m_Percent(0)
	,m_Alive(nullptr),m_ActObject(nullptr)
	{}

	HPObject::~HPObject(){}

	void HPObject::initBackground( const char* pPath )
	{
		m_Background = CCSprite::create(pPath);
		if( m_Background != nullptr )
		{
			this->addChild(m_Background);
		}else{
			CCLOG("[ *ERROR ] HPObject::initBackground");
			m_Background = NULL;
			return;
		}
		this->setContentSize(m_Background->getContentSize());
	}

	void HPObject::setSkinDirection()
	{
		if ( !m_Skin)
			return ;
		if (m_Alive->getOtherCamp())
		{
			m_Skin->setBarChangeRate(ccp(1,0));
			m_Skin->setMidpoint(ccp(0,0));
		}else{
			m_Skin->setBarChangeRate(ccp(1,0));
			m_Skin->setMidpoint(ccp(1,0));
		}
	}

	void HPObject::initSkinByEnemy()
	{
		if (m_Alive->getOtherCamp())
		{
			initSkin("warScene/bar_yellow.png");
		}else{
			initSkin("warScene/bar_green.png");
		}
		setSkinDirection();
	}

	void HPObject::initSkin( const char* pPath )
	{
		CCSprite* tSkin = CCSprite::create(pPath);
		if (tSkin)
		{
			m_Skin = CCProgressTimer::create(tSkin);
			m_Skin->setType(kCCProgressTimerTypeBar);

			m_Skin->setPercentage(0.0f);
			this->addChild( m_Skin );
		}else{
			CCLOG("[ *ERROR ] HPObject::initSkin %s",pPath);
			m_Skin = nullptr;
			return ;
		}
	}

	void HPObject::initHp(AliveObject* pAlive)
	{
		m_ActObject = pAlive;
		m_Alive = pAlive->getBaseRole();
		initBackground("public/black.png");
		initSkinByEnemy();
		this->setHpNumberMax(m_Alive->getMaxHp());
		this->setHpNumber(m_Alive->getHp());
		showHp(nullptr);
	}

	void HPObject::setHpNumber(float hp)
	{
		if( m_HpNumber == hp )
			return;
		m_HpNumber = hp;
		if (m_HpNumber >= m_HpNumberMax)
			m_HpNumber = m_HpNumberMax;
		updateShow();
	}
	float HPObject::getHpNumber(){return m_HpNumber;}

	void HPObject::setHpNumberMax(float maxHp)
	{
		if( m_HpNumberMax == maxHp ) return;
		m_HpNumberMax = maxHp;
		updateShow();
	}
	float HPObject::getHpNumberMax(){return m_HpNumberMax;}

	void HPObject::updateShow()
	{
		if( m_HpNumberMax <= 0 ) return;
		m_Percent = m_HpNumber / m_HpNumberMax * 100;
		if( !m_Skin ) 
			return;
		float oldPe = m_Skin->getPercentage();
		CCProgressFromTo* proto = CCProgressFromTo::create(0.3f,oldPe,m_Percent);
		m_Skin->runAction(proto);
	}

	CCSequence* HPObject::normalAction(int pDistance)
	{
		CCScaleTo* sc = CCScaleTo::create(0.15f,1.3f);
		CCScaleTo* sc1 = CCScaleTo::create(0.15f,1.0f);
		CCMoveBy* moveBy = CCMoveBy::create(0.25f, ccp(0,pDistance));
		CCFadeOut* fadeout = CCFadeOut::create(0.6f);
		CCDelayTime* dely = CCDelayTime::create(0.25f);
		CCSpawn* spw = CCSpawn::create((CCMoveBy*)moveBy->copy(),(CCFadeOut*)fadeout->copy(),NULL);
		CCSequence* tSequence = CCSequence::create(sc,sc1,dely,spw, CCRemoveSelf::create() , NULL);
		return tSequence;
	}

	CCSequence* HPObject::critAction( int pDistance )
	{
		CCScaleTo* tScaleTo = CCScaleTo::create(0.05f,1);
		CCScaleTo* tScaleTo2 = CCScaleTo::create(0.1f,2.3f);
		CCMoveBy* tMoveBy = CCMoveBy::create(0.2f, ccp(0,pDistance));
		CCSpawn* tSpawn = CCSpawn::create(tScaleTo,tMoveBy,NULL);
		CCFadeOut* tFadeOut = CCFadeOut::create(1.3f);
		CCDelayTime* tDelaty = CCDelayTime::create(0.25f);
		CCSequence* tSequence = CCSequence::create(tSpawn,tScaleTo2,tDelaty,tFadeOut,CCRemoveSelf::create(),NULL);
		return tSequence;
	}

	CCSequence* HPObject::critBackgroundAction( int pDistance )
	{
		CCDelayTime* tDelay = CCDelayTime::create(0.25f);
		CCScaleTo* tScaleTo = CCScaleTo::create(0.05f,1);
		CCScaleTo* tScaleTo2 = CCScaleTo::create(0.1f,1.2f);
		CCMoveBy* tMoveBy = CCMoveBy::create(0.05f, ccp(0,pDistance));
		CCSpawn* tSpawn = CCSpawn::create(tScaleTo,tMoveBy,NULL);
		CCFadeOut* tFadeOut = CCFadeOut::create(0.8f);
		CCSequence* tSequence = CCSequence::create(tSpawn,tScaleTo2,tDelay,tFadeOut,CCRemoveSelf::create(),NULL);
		return tSequence;
	}

	void HPObject::missEffect()
	{
		CCSprite*font = CCSprite::create("label/miss.png");
		m_ActObject->addChild(font);
		font->runAction(normalAction(maxMoveDistance(font)));
		font->setPosition(ccp(-100,0));
	}

	void HPObject::runActionByType( PlayHpType pType,CCNode* pLabel )
	{
		int tDistance = maxMoveDistance(pLabel);
		if (pType >=  PlayHpType::genralCritType)
		{
			pLabel->setScale(0.1f);
			pLabel->runAction(critAction(tDistance));
			critBackgroundEffect(tDistance);
		}else{
			pLabel->runAction(normalAction(tDistance));
		}
	}

	void HPObject::critBackgroundEffect( int pDistance )
	{
		CCSprite* tCritBackground = CCSprite::create("warScene/blood_mobile.png");
		if (m_Alive->getEnemy())										//暴击的显示方式，字体旋转一定角度，敌我双方显示位置不同
		{
			tCritBackground->setPosition(ccp(-40,120));
		}else{
			tCritBackground->setPosition(ccp(20,120));
		}
		tCritBackground->runAction(critBackgroundAction(pDistance));
		m_ActObject->addChild(tCritBackground);
	}

	void HPObject::offsByEnemy( CCNode* pLabel )
	{
		pLabel->setPosition(ccp(-30,50));
	}

	void HPObject::gainNumberPlay( int pChangeNumber )
	{
		string str ="."+string(ToString(abs(pChangeNumber)));
		CCLabelAtlas* tNumberLabel = CCLabelAtlas::create(str.c_str(),"label/green.png",31,39,46);
		m_ActObject->addChild(tNumberLabel,1);
		setHpNumber(m_HpNumber + abs(pChangeNumber));								//存在交替变化的清楚出现如果合击的话
		PlayEffectSound(SFX_513);
		if (!tNumberLabel)
		{
			CCLOG("[ *ERROR ] HPObject::gainNumberPlay = %d",m_Alive->getModel());
			return;
		}
		offsByEnemy(tNumberLabel);
		tNumberLabel->runAction(normalAction(maxMoveDistance(tNumberLabel)));
	}

	void HPObject::lostNumberPlay( int pChangeNumber,PlayHpType pType )
	{
		string str ="/"+string(ToString(abs(pChangeNumber)));
		CCLabelAtlas* tNumberLabel = CCLabelAtlas::create(str.c_str(),"label/myred.png",31,39,46); 
		m_ActObject->addChild(tNumberLabel,1);
		setHpNumber(m_HpNumber - abs(pChangeNumber));	
		if (!tNumberLabel)
		{
			CCLOG("[ *ERROR ] HPObject::lostNumberPlay = %d",m_Alive->getModel());
			return;
		}
		offsByEnemy(tNumberLabel);
		runActionByType(pType,tNumberLabel);
	}

	void HPObject::playChangeNumber(int pChangeNumber,PlayHpType pType)
	{
		showHp(nullptr);
		switch (pType)
		{
		case PlayHpType::typeface:
			{
				missEffect();
			}break;
		case PlayHpType::gainType:
			{
				gainNumberPlay(pChangeNumber);
			}break;
		default:
			{
				lostNumberPlay(pChangeNumber,pType);
			}break;
		}
	}

	void HPObject::showHp( CCObject* ob )
	{
		this->unschedule(schedule_selector(HPObject::hideHp));
		this->setVisible(true);
		this->scheduleOnce(schedule_selector(HPObject::hideHp),5.0f);
	}

	void HPObject::hideHp( float dt )
	{
		if (!m_Alive->getCaptain())
			this->setVisible(false);
	}

	int HPObject::maxMoveDistance( CCNode* pLabel )
	{
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		int tRandom = CCRANDOM_0_1()*50 + 70;
		int tHight = pLabel->getParent()->convertToWorldSpace(pLabel->getPosition()).y;
		if ( tHight + tRandom > size.height )
			return size.height - tHight - 80;
		return tRandom;
	}

}
