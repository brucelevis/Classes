﻿#include "PvpGateLayer.h"
#include "common/CGameSound.h"
#include "Resources.h"
#include "GMessage.h"
#include "model/DataDefine.h"
#include "tools/ShowTexttip.h"
#include "pvp_ui/SelectChallengeLayer.h"
#include "netcontrol/CPlayerControl.h"
#include "mainCity/mainScene.h"
#include "Global.h"
#include "SDK/GamePlatfomDefine.h"
#include "model/DataCenter.h"
#include "SDK/FaceBookSDK.h"
#include "common/CommonFunction.h"

CPvpGateLayer::CPvpGateLayer():
	m_ui(nullptr), m_pCloudyTranstion(nullptr),m_fogLay(nullptr),m_fogLay1(nullptr),m_fMiddleLayer(nullptr),m_iGateLevel(0),m_iRank(0),m_iRoleRank(0)
{
}

CPvpGateLayer::~CPvpGateLayer()
{

}

bool CPvpGateLayer::init()
{
	if(BaseLayer::init())
	{
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		//内容
		m_ui = LoadComponent("pvp_gate_layer.xaml");
		m_ui->setPosition(VCENTER);
		this->addChild(m_ui);

		setIsShowBlack(false);
		setVisible(false);
		setTouchPriority(-2);

		//同步竞技场
		{
			CImageView* pBtn = (CImageView*)m_ui->findWidgetById("click_1");
			pBtn->setTouchEnabled(true);
			pBtn->setOnClickListener(this, ccw_click_selector(CPvpGateLayer::pvpAsynchronization));
		}


		//异步竞技场
		{
			CImageView* pBtn = (CImageView*)m_ui->findWidgetById("click_2");
			pBtn->setTouchEnabled(true);
			pBtn->setOnClickListener(this, ccw_click_selector(CPvpGateLayer::pvpSynchronization));
		}

		//退出
		{
			CImageView* pBtn = (CImageView*)m_ui->findWidgetById("click_3");
			pBtn->setTouchEnabled(true);
			pBtn->setOnClickListener(this, ccw_click_selector(CPvpGateLayer::onClose));
		}
		{
			CImageView* pBtn = (CImageView*)m_ui->findWidgetById("click_4");
			pBtn->setTouchEnabled(true);
			pBtn->setOnClickListener(this, ccw_click_selector(CPvpGateLayer::onClose));
		}

		//雾
		m_fogLay = (CLayout *)m_ui->findWidgetById("fog2");
		m_fogLay1 =(CLayout*)m_ui->findWidgetById("fog3");
		this->runBloodFogAction();

		//云
		runCloud();

		m_fMiddleLayer = (CLayout *)m_ui->findWidgetById("middle");
		
		//过渡云
		initCloundyTranstion();

		//大红蓝按钮
		initBaseBuild();

		m_ui->setScale(1.3f);

		//箭头上下
		CImageView *pArrow = (CImageView *)m_ui->findWidgetById("arrow");
		pArrow->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(
			CCMoveBy::create(0.3f, ccp(0, 10)),
			CCMoveBy::create(0.3f, ccp(0, -10))
			)));

		CLayout *pFacebookLayer = (CLayout *)m_ui->findWidgetById("layer_facebook");
		pFacebookLayer->setVisible(false);

		return true;
	}

	return false;
}


void CPvpGateLayer::setGateLevel( int iRank )
{
	m_iRank = iRank;
	//根据等级划分
	//僵尸皇
	if(m_iRank == 1)
	{
		m_iGateLevel = 3;
		m_iRoleRank = 1;
	}
	//皇族
	else if(m_iRank>=2 && m_iRank<= 10)
	{
		m_iGateLevel = 3;
		m_iRoleRank = 2;
	}
	//贵族
	else if(m_iRank>=11 && m_iRank<=50)
	{
		m_iGateLevel = 3;
		m_iRoleRank = 3;
	}
	//天师
	else if(m_iRank>=51 && m_iRank<=100)
	{
		m_iGateLevel = 2;
		m_iRoleRank = 4;
	}
	//行者
	else if(m_iRank>=101 && m_iRank<=1000)
	{
		m_iGateLevel = 2;
		m_iRoleRank = 5;
	}
	//平民  1000+
	else
	{
		m_iGateLevel = 1;
		m_iRoleRank = 6;
	}

	//m_iGateLevel = (int(CCRANDOM_0_1()*100))%3+1;

	//建筑
	initBuilding();
}

void CPvpGateLayer::runBloodFogAction()
{
	float width = 1308;//cloud->getContentSize().width;

	CCMoveBy* move = CCMoveBy::create(60.0f,ccp(-width,0));
	CCMoveBy* moveb = CCMoveBy::create(60.0f,ccp(-width,0));
	CCSequence *sequence = CCSequence::create(move,CCCallFuncN::create(this,callfuncN_selector(CPvpGateLayer::relocation)),moveb,nullptr);
	m_fogLay->runAction(CCRepeatForever::create(sequence));

	m_cloudPos = m_fogLay->getPosition();

	// 	CCSprite *cloud1  =  (CCSprite *)(m_fogLay->findWidgetById("cloud1"));
	m_cloudAPos = m_fogLay1->getPosition();

	CCMoveBy* move1 = CCMoveBy::create(120.0f,ccp(-width*2,0));
	CCSequence *sequence1 = CCSequence::createWithTwoActions(move1,CCCallFuncN::create(this,callfuncN_selector(CPvpGateLayer::relocation)));
	m_fogLay1->runAction(CCRepeatForever::create(sequence1));
}

void CPvpGateLayer::relocation( CCNode* pSender )
{
	CLayout *cloud = (CLayout*)pSender;
	float width = 1308;/*cloud->getContentSize().width;*/
	CCPoint pos; 
	if (strcmp(cloud->getId(),"fog2")==0)
	{
		pos = ccpAdd(m_cloudPos,ccp(width,0));
		cloud->setPosition(pos);
	}
	else
	{
		cloud->setPosition(m_cloudAPos);
	}
}

void CPvpGateLayer::onEnter()
{
	BaseLayer::onEnter();

	GetTcpNet->registerMsgHandler(PvpCityDataMsg, this, CMsgHandler_selector(CPvpGateLayer::processNetMsg));
}

void CPvpGateLayer::onExit()
{
	BaseLayer::onExit();

	GetTcpNet->unRegisterAllMsgHandler(this);
}

void CPvpGateLayer::onClose( CCObject* pSender )
{
	//重置锚点
	ResetAnchorPointAndKeepSamePos(m_ui, ccp(0.5f, 0.4f));
	//屏蔽触摸
	setTouchEnabled(false);
	//缩放
	m_ui->runAction(
		CCSpawn::create(
		CCSequence::createWithTwoActions(CCDelayTime::create(0.2f), CCCallFunc::create(this, callfunc_selector(CPvpGateLayer::showEffectOut))),
		CCScaleTo::create(0.3f, 1.5f),
		nullptr)
		);
}

void CPvpGateLayer::pvpSynchronization( CCObject* pSender )
{
	PlayEffectSound(SFX_413);
	ShowPopTextTip("open later!");
	return;
}

void CPvpGateLayer::pvpAsynchronization( CCObject* pSender )
{
	PlayEffectSound(SFX_424);
	
	showAsynPvp();
}

void CPvpGateLayer::showEffectIn()
{
	//TODO
	//PVP场景进场动画
	//云进入
	//云动作
	//延迟0.5f生成建筑物
	//云出
	//动画完成

	setVisible(true);

	m_ui->setVisible(false);

	showCloundyTranstion();

	runAction(CCSequence::create(
		CCDelayTime::create(0.5f),
		CCCallFunc::create(this, callfunc_selector(CPvpGateLayer::postMsgToCleanMainCityRes)),
		CCCallFunc::create(this, callfunc_selector(CPvpGateLayer::showBuilding)),
		nullptr
		));
}

void CPvpGateLayer::showEffectOut()
{
	//TODO
	//PVP场景进场动画
	//云进入
	//云动作
	//延迟0.5f隐藏建筑物
	//云出
	//摧毁当前层
	//动画完成

	showCloundyTranstion(true);
	runAction(CCSequence::create(
		CCDelayTime::create(0.5f),
		CCCallFunc::create(this, callfunc_selector(CPvpGateLayer::postMsgToRebuildMainCityRes)),
		CCCallFunc::create(this, callfunc_selector(CPvpGateLayer::hideBuilding)),
		nullptr
		));
}

void CPvpGateLayer::initCloundyTranstion()
{
	SkeletonAnimation *pSkeletonAnimation = SkeletonAnimation::createWithFile("pvp/gate/yun.json", "pvp/gate/yun.atlas", 1);
	pSkeletonAnimation->setPosition(ccp(VCENTER.x, 0));
	this->addChild(pSkeletonAnimation);
	pSkeletonAnimation->completeListener = std::bind(&CPvpGateLayer::SpineComplete, this, std::placeholders::_1, std::placeholders::_2);

	m_pCloudyTranstion = pSkeletonAnimation;
}

void CPvpGateLayer::showCloundyTranstion( bool bFlipY )
{
	if(m_pCloudyTranstion == nullptr)
	{
		initCloundyTranstion();
	}

	//m_pCloudyTranstion->setScaleY(bFlipY?-1:1);
	m_pCloudyTranstion->setVisible(true);
	m_pCloudyTranstion->setAnimation(0,  bFlipY?"stand2":"stand1", false);

	PlayEffectSound(SFX_422);
}

void CPvpGateLayer::hideCloundyTranstion()
{
	m_pCloudyTranstion->setVisible(false);
}


void CPvpGateLayer::initBuilding()
{
	//同步PVP
	{
		CCPoint pPosLeft[3] = {ccp(150, 35), ccp(147, 35), ccp(149, 35)};

		SkeletonAnimation *pSkeletonAnimation = SkeletonAnimation::createWithFile(
			CCString::createWithFormat("pvp/gate/zuojian_%d.json", m_iGateLevel)->getCString(), 
			CCString::createWithFormat("pvp/gate/zuojian_%d.atlas", m_iGateLevel)->getCString(), 
			0.9f);
		pSkeletonAnimation->setPosition(pPosLeft[m_iGateLevel-1]);
		pSkeletonAnimation->setAnimation(0, "stand", true);
		m_fMiddleLayer->addChild(pSkeletonAnimation, 1);
	}

	//异步PVP
	{
		CCPoint pPosRight[3] = {ccp(970, 50), ccp(990, -5), ccp(990, -10)};

		SkeletonAnimation *pSkeletonAnimation = SkeletonAnimation::createWithFile(
			CCString::createWithFormat("pvp/gate/youjian_%d.json", m_iGateLevel)->getCString(), 
			CCString::createWithFormat("pvp/gate/youjian_%d.atlas", m_iGateLevel)->getCString(), 
			0.9f);
		pSkeletonAnimation->setPosition(pPosRight[m_iGateLevel-1]);
		pSkeletonAnimation->setAnimation(0, "stand", true);
		m_fMiddleLayer->addChild(pSkeletonAnimation, 2);
	}

}


void CPvpGateLayer::initBaseBuild()
{
	//按钮
	{
		SkeletonAnimation *pSkeletonAnimation = SkeletonAnimation::createWithFile(
			"pvp/gate/hong_pve.json", 
			"pvp/gate/hong_pve.atlas", 
			0.9f);
		pSkeletonAnimation->setPosition(ccp(253, 351));
		pSkeletonAnimation->setAnimation(0, "stand", true);
		m_fMiddleLayer->addChild(pSkeletonAnimation, 4);
	}

	//按钮
	{
		SkeletonAnimation *pSkeletonAnimation = SkeletonAnimation::createWithFile(
			"pvp/gate/lan_pvp.json", 
			"pvp/gate/lan_pvp.atlas", 
			0.9f);
		pSkeletonAnimation->setPosition(ccp(985, 321));
		pSkeletonAnimation->setAnimation(0, "stand", true);
		m_fMiddleLayer->addChild(pSkeletonAnimation, 4);
	}

	//塔
	{
		SkeletonAnimation *pSkeletonAnimation = SkeletonAnimation::createWithFile("pvp/gate/zhongjian.json", "pvp/gate/zhongjian.atlas", 0.87f);
		pSkeletonAnimation->setPosition(ccp(DESIGN_WIDTH/2, 80));
		pSkeletonAnimation->setAnimation(0, "stand", true);
		m_fMiddleLayer->addChild(pSkeletonAnimation, 3);
	}
}



void CPvpGateLayer::showBuilding()
{
	m_ui->setVisible(true);
	m_ui->runAction(
		CCSequence::create(
		CCDelayTime::create(0.5f), 
		CCScaleTo::create(1.2f, 1.0f),
		CCCallFunc::create(this, callfunc_selector(CPvpGateLayer::showAllUILayer)),
		nullptr
		));
}


void CPvpGateLayer::hideBuilding()
{
	m_ui->setVisible(false);
}

void CPvpGateLayer::postMsgToCleanMainCityRes()
{
	//清除主场景资源，其实不清楚也行，没有怎么样，反而搞来搞去会卡顿
	//TODO
	//NOTIFICATION->postNotification("CMainScene::removeCityBuildLayer");

}

void CPvpGateLayer::postMsgToRebuildMainCityRes()
{
	//TODO
	//NOTIFICATION->postNotification("CMainScene::addCityBuildLayer");
	NOTIFICATION->postNotification("CMainCityBuild::backFromPvp");
}


void CPvpGateLayer::SpineComplete( int trackIndex, int loopCount )
{
	SkeletonAnimation* skeletonNode = dynamic_cast<SkeletonAnimation*>(m_pCloudyTranstion);
	if (skeletonNode)
	{
		CCLOG("[ info ]	 CPvpGateLayer::SpineComplete");
		m_pCloudyTranstion->setVisible(false);

		//场景都不可见了，移除掉，退出动画常用
		if(!m_ui->isVisible())
		{
			NOTIFICATION->postNotification("CMainScene::removePvpGateLayer");
		}

	}
}

void CPvpGateLayer::runCloud()
{
	for(int i=0; i<3; i++)
	{
		CImageView *pImage = (CImageView *)m_ui->findWidgetById(CCString::createWithFormat("cloud%d", i+1)->getCString());
		pImage->runAction(
				CCRepeatForever::create(
					CCSequence::create(
						CCMoveBy::create(1500/(50+CCRANDOM_0_1()*50), ccp(1500, 0)),
						CCMoveTo::create(0, ccp(-200, pImage->getPositionY())),
						nullptr
					)
				)
			);
	}
}

bool CPvpGateLayer::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	bool res = CWidgetWindow::ccTouchBegan(pTouch,pEvent);
	return true;
}

void CPvpGateLayer::showAllUILayer()
{
	CLayout *pDownLayer1 = (CLayout *)m_ui->findWidgetById("down_1");
	showUI(pDownLayer1);
	CLayout *pDownLayer3 = (CLayout *)m_ui->findWidgetById("down_3");
	pDownLayer3->setVisible(true);
	CLayout *pFacebookLayer = (CLayout *)m_ui->findWidgetById("layer_facebook");
	pFacebookLayer->setVisible(true);
}

void CPvpGateLayer::showUI( CLayout *pDownLayer )
{
	//底层UI
	CLayout *pLayout = pDownLayer;
	pLayout->setVisible(true);

	//奖杯
	CImageView *pCupImage = (CImageView *)pDownLayer->getChildByTag(2);
	CCTexture2D *pCupTexture = CCTextureCache::sharedTextureCache()->addImage(CCString::createWithFormat("pvp/gate/cup_%d.png", m_iRoleRank)->getCString());
	if (pCupTexture)
	{
		pCupImage->setTexture(pCupTexture);
	}
	else
	{
		pCupImage->setVisible(false);
	}

	//添加六边形特效
	SkeletonAnimation *pSkeletonAnimation = SkeletonAnimation::createWithFile("pvp/gate/pian.json", "pvp/gate/pian.atlas", 1);
	pSkeletonAnimation->setPosition(ccp(349, 26));
	pLayout->addChild(pSkeletonAnimation, 2);
	pSkeletonAnimation->completeListener = std::bind(
		[pSkeletonAnimation]( int iData1, int iData2 ){ 
			if(iData1 == 0)
			{
				pSkeletonAnimation->setAnimation(1, "stand2", true); 
			}
		},
		std::placeholders::_1, std::placeholders::_2
		);
	//pSkeletonAnimation->setVisible(pCupImage->isVisible());
	

	//称号
	CImageView *pTitle = (CImageView *)pDownLayer->getChildByTag(3);
	CCTexture2D *pTitleTexture = CCTextureCache::sharedTextureCache()->addImage(CCString::createWithFormat("pvp/gate/type_%d.png", m_iRoleRank)->getCString());
	if (pTitleTexture)
	{
		pTitle->setTexture(pTitleTexture);
	}
	else
	{
		pTitle->setVisible(false);
	}

	//排名
	CLabelAtlas *pRank = CLabelAtlas::create(ToString(m_iRank), "pvp/gate/pvp_number2.png", 34, 54, '0');
	pRank->setPosition(ccp(188, 35));
	pRank->setAnchorPoint(CCPointCenter);
	if(m_iRank > 1000)
	{
		pRank->setScale(0.7f);
		pRank->setString("1000:");
	}
	pLayout->addChild(pRank);

	//横条
	CImageView *pBlank = (CImageView *)pDownLayer->getChildByTag(4);

	//ranking
	CLabel *pRanking = (CLabel *)pDownLayer->getChildByTag(5);
	

	//动画-横条飞出-ranking显示-（六边形显示-奖杯落下）-名字显示
	pBlank->setPositionX(pBlank->getPositionX()-410);
	pBlank->runAction(CCMoveBy::create(0.2f, ccp(+410, 0)));

	pRank->setOpacity(0);
	pRank->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.2f), CCFadeIn::create(0.3f)));
	pRanking->setOpacity(0);
	pRanking->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.2f), CCFadeIn::create(0.3f)));

	pSkeletonAnimation->setOpacity(0);
	pSkeletonAnimation->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.5f), CCCallFuncN::create(this, callfuncN_selector(CPvpGateLayer::callbackForSpineAnimate))));

	pCupImage->setOpacity(0);
	pCupImage->setPositionY(pCupImage->getPositionY() + 180);
	pCupImage->runAction(CCSequence::create(
		CCDelayTime::create(0.5f), 
		CCSpawn::createWithTwoActions(
			CCFadeIn::create(0.2f), 
			CCEaseBackOut::create(CCMoveBy::create(0.3f, ccp(0, -180)))
		),
		nullptr
		));

	pTitle->setOpacity(0);
	pTitle->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.7f), CCFadeIn::create(0.2f)));
}

void CPvpGateLayer::callbackForSpineAnimate( CCNode *pSender )
{
	SkeletonAnimation *pSkeletonAnimation = ( SkeletonAnimation *)pSender;
	pSkeletonAnimation->setAnimation(0, "stand1", false);
	pSkeletonAnimation->setOpacity(255);
}

void CPvpGateLayer::showAsynPvp()
{
	//进入异步PVP，选择队伍
	CSelectChallengeLayer* pChange = CSelectChallengeLayer::create();
	LayerManager::instance()->push(pChange);
	CPlayerControl::getInstance().askForPvpChallenge(false);
}

void CPvpGateLayer::initNumberOneInfo( const Opponent &pOpponent )
{
	//头像，名字
	CLabel *name = (CLabel*)(m_ui->findWidgetById("name"));
	name->setString(pOpponent.role_name().c_str());

	CCSprite *headbg = (CCSprite*)(m_ui->findWidgetById("headbg"));
	CImageView *headImg = (CImageView*)(m_ui->findWidgetById("headImg"));
	int iThumb = pOpponent.role_thumb();
	if (iThumb>0)
	{
		CCTexture2D *texture = CCTextureCache::sharedTextureCache()
			->addImage(CCString::createWithFormat("headIcon/%d.png", iThumb)->getCString());
		if (texture)
		{
			headImg->setTexture(texture);
		}
		headImg->setFlipY(false);

	}
	else
	{
		string fbName = /*CCFileUtils::sharedFileUtils()->getWritablePath()+*//*"download/fbImg/"+*/pOpponent.fb_id()+".jpg";
		string fullName = CCFileUtils::sharedFileUtils()->fullPathForFilename(fbName.c_str());
		bool isFileExist = CCFileUtils::sharedFileUtils()->isFileExist(fullName);

		if(isFileExist)
		{
			CImageView *sp = CImageView::create(fbName.c_str());
			if (sp)
			{	
				CCNode *pParent = headImg->getParent();
				CImageView *spr = MakeFaceBookHeadToCircle(sp);		
				spr->setPosition(headbg->getPosition());
				headImg->removeFromParentAndCleanup(true);
				spr->setId("headImg");
				pParent->addChild(spr);
			}
			else
			{
				CCLOGERROR("%s error", fullName.c_str());
			}

		}
		// 		else
		// 		{
		// 			HttpLoadImage::getInstance()->bindUiTarget(this);
		// 			CCString *imgUrl = CCString::createWithFormat(FACEBOOKIMG_106,data->getFbId().c_str());
		// 			HttpLoadImage::getInstance()->requestUrlImage(imgUrl->getCString(),data->getFbId().c_str());
		// 		}
	}
}

void CPvpGateLayer::initFacebookShareBtn( int myRank )
{
	//分享按钮, 只有第一名分享
	CButton* pBtn = (CButton*)m_ui->findWidgetById("fbBtn");
	if (myRank == 1)
	{
		pBtn->setVisible(true);
		pBtn->setOnClickListener(this, ccw_click_selector(CPvpGateLayer::shareToFaceBook));
	}
	else
	{
		pBtn->setVisible(false);
	}
}

void CPvpGateLayer::processNetMsg( int type, google::protobuf::Message *msg )
{
	if (type != PvpCityDataMsg)
	{
		return;
	}

	PvpCityData *pPvpCityData = dynamic_cast<PvpCityData *>(msg);
	if (!pPvpCityData)
	{
		return;
	}

	setGateLevel(pPvpCityData->my_pve_rank());

	//NOTIFICATION->postNotification("CMainCityBuild::showPvpActionToSky");

#ifdef FACEBOOKSHARE
	initNumberOneInfo(pPvpCityData->pve_champion());
	initFacebookShareBtn(pPvpCityData->my_pve_rank());
#endif
}

void CPvpGateLayer::shareToFaceBook( CCObject *pSender )
{
	const ShareData *data = DataCenter::sharedData()->getShareData()->getCfg(11);
	CCString *strDesc = CCString::createWithFormat(data->desc.c_str(), m_iRank);
	CCString *strUrl = CCString::createWithFormat(data->url.c_str(), m_iRank);
	FaceBookSDK::sharedInstance()->onShareToFb(strDesc->getCString(), strUrl->getCString());
}
