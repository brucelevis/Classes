﻿#include "CombatGuideLayer.h"
#include "TouchIntercept.h"
#include "model/DataCenter.h"
#include "model/WarManager.h"
#include "model/MapManager.h"
#include "scene/alive/AliveDefine.h"
#include "scene/layer/WarMapLayer.h"
#include "scene/layer/WarAliveLayer.h"
#include "CombatGuideData.h"
#include "CombatGuideManage.h"
#include "warscene/ConstNum.h"
#include "scene/WarScene.h"
#include "WarControl.h"
#include "GMessage.h"
#include "scene/WarScene.h"
#include <string>
#include "common/CommonFunction.h"
#include "Battle/LoadSpineData.h"
CombatGuideLayer::CombatGuideLayer()
	:m_TouchIntercept(nullptr),m_Clipping(nullptr),m_TextRect(nullptr)
	,m_Step(nullptr),m_root(nullptr),m_mapData(nullptr)
	,m_RenderTexture(nullptr),m_Scene(nullptr),m_LayerColor(nullptr)
{}

#if _Test_Guide_	//测试方案
//方案2   判断触摸是否在裁剪节点区域内
//方案3   以一个精灵作为触摸区域,其他区域填充灰色精灵。
void CombatGuideLayer::ClippingNodeTest()
{
	CCSize size = CCDirector::sharedDirector()->getVisibleSize(); 
	m_Clipping=CCClippingNode::create();
	m_Clipping->setInverted(true);				//设置底板可见
	m_Clipping->setAlphaThreshold(0.0f);		//设置透明度为0
	CCLayerColor* back=CCLayerColor::create(ccc4(0,0,0,200));
	m_Clipping->addChild(back);
	this->addChild(m_Clipping);
	//以下模型是带图像遮罩(可以将多个节点加在一个node做遮罩处理)
	CCSprite* close=CCSprite::create("public/guide/finger.png");
	close->setPosition(ccp(100,100));
	close->setAnchorPoint(CCPointZero);
	CCSprite* sp = CCSprite::create("public/guide/finger.png");
	sp->setAnchorPoint(CCPointZero);
	sp->setPosition(ccp(250,250));
	m_Clipping->setStencil(sp);
	CCRect bigRect = CCRect(sp->getPositionX()-50,sp->getPositionY()-50,sp->getContentSize().width+100,sp->getContentSize().height+100);
	CCRect smallRect = CCRect(sp->getPositionX(),sp->getPositionY(),sp->getContentSize().width,sp->getContentSize().height);
	bool isTest = false;				//是否开启测试模式
	bool isOppopset = false;			//是否翻转触摸区域 //图形是不规则图形,但是绘制只能绘制出正方形。
	m_TouchIntercept = TouchIntercept::create(guideLayerPriority,bigRect,smallRect,isOppopset,isTest);
	this->addChild(m_TouchIntercept);


	/*绘制圆形区域*/
	//设置参数
	static ccColor4F red={1,0,0,1};//顶点颜色设置为红色，参数是R,G,B,透明度
	float radius=55.0f;//设置圆的半径
	const int nCount=200;//设置顶点数，此处我们将圆看成200边型
	const float angel=2.0f * (float)M_PI/nCount;//两个顶点与中心的夹角（弧度）
	static CCPoint circle[nCount];  //保存顶点的数组
	for(int i=0;i<nCount;i++){
		float radian=i*angel; //弧度
		circle[i].x=radius * cosf(radian);//顶点x坐标
		circle[i].y=radius * sinf(radian);//顶点y坐标
	}
	/*绘制多边形*/
	//注意不要将pStencil addChild
	CCDrawNode *pStencil=CCDrawNode::create();
	pStencil->drawPolygon(circle, nCount, red, 0, red);//绘制这个多边形(200个顶点的多边形就是圆了)

	/*给圆添加一个放大缩小动作*/
	pStencil->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCScaleBy::create(0.05f, 0.95f),
		CCScaleTo::create(0.125f, 1))));
	pStencil->setPosition(ccp(size.width/2, size.height/2));
	/*将这个圆形从剪裁节点上面抠出来，Stencil是模板的意思*/
	m_Clipping->setStencil(pStencil);


	CCSprite * sCircle= createSprite("circle.png", size.width/2, size.height/2);//挖出触摸区域后盖一个精灵上去
	sCircle->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(
		CCScaleBy::create(0.05f, 0.95f),
		CCScaleTo::create(0.125f, 1))));
	this->addChild(sCircle);
	this->addChild(createSprite("hand.png", size.width*1/3, size.height/2));
}

CCSprite * CombatGuideLayer::createSprite(const char * name,float point_x,float point_y)
{
	/*快速创建精灵的方法*/
	CCSprite * sprite=CCSprite::create(name);
	sprite->setPosition(ccp(point_x,point_y));
	return sprite;
}

void CombatGuideLayer::DrawNodeTest()
{
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	CCDrawNode *draw = CCDrawNode::create();
	m_Clipping->addChild(draw, 10);

	ccBlendFunc blend;
	blend.src = GL_ZERO;
	blend.dst = GL_ONE_MINUS_SRC_ALPHA;
	//draw->setBlendFunc(blend);				//可以让节点全变成灰黑色的效果(制作动态光晕)

	// Draw 10 circles
	for( int i=0; i < 10; i++)
	{
		draw->drawDot(ccp(s.width/2, s.height/2), 10*(10-i), ccc4f(CCRANDOM_0_1(), CCRANDOM_0_1(), CCRANDOM_0_1(), 1));
	}

	// Draw polygons
	CCPoint points[] = { CCPoint(s.height/4,0), CCPoint(s.width,s.height/5), CCPoint(s.width/3*2,s.height) };
	draw->drawPolygon(points, sizeof(points)/sizeof(points[0]), ccc4f(1,0,0,0.5), 4, ccc4f(0,0,1,1));

	// star poly (triggers buggs)
	{
		const float o=80;
		const float w=20;
		const float h=50;
		CCPoint star[] = 
		{
			CCPoint(o+w,o-h), CCPoint(o+w*2, o),						// lower spike
			CCPoint(o + w*2 + h, o+w ), CCPoint(o + w*2, o+w*2),		// right spike
			//				{o +w, o+w*2+h}, {o,o+w*2},					// top spike
			//				{o -h, o+w}, {o,o},							// left spike
		};
		draw->drawPolygon(star, sizeof(star)/sizeof(star[0]), ccc4f(1,0,0,0.5), 1, ccc4f(0,0,1,1));
	}
	// star poly (doesn't trigger bug... order is important un tesselation is supported.		//这个大括号的作用是防止变量重定义使用的
	{
		const float o=180;
		const float w=20;
		const float h=50;
		CCPoint star[] = {
			CCPoint(o,o), CCPoint(o+w,o-h), CCPoint(o+w*2, o),		// lower spike
			CCPoint(o + w*2 + h, o+w ), CCPoint(o + w*2, o+w*2),	// right spike
			CCPoint(o +w, o+w*2+h), CCPoint(o,o+w*2),				// top spike
			CCPoint(o -h, o+w),                                     // left spike
		};

		draw->drawPolygon(star, sizeof(star)/sizeof(star[0]), ccc4f(1,0,0,0.5), 1, ccc4f(0,0,1,1));
	}
	// Draw segment
	draw->drawSegment(ccp(20,s.height), ccp(20,s.height/2), 10, ccc4f(0, 1, 0, 1));
	draw->drawSegment(ccp(10,s.height/2), ccp(s.width/2, s.height/2), 40, ccc4f(1, 0, 1, 0.5));
}

#endif

CombatGuideLayer::~CombatGuideLayer()
{
	CC_SAFE_RELEASE(m_root);
	m_root = nullptr;
	m_VecRect.clear();
}

bool CombatGuideLayer::init()
{
	if (BaseLayer::init())
	{
		this->setTouchPriority(guideLayerPriority);
		this->setTouchEnabled(true);
		this->setIsShowBlack(false);
		m_root = CCNode::create();
		m_root->setContentSize(CCSizeMake(1138, 640));
		m_root->setAnchorPoint(ccp(0.5f, 0.5f));
		m_root->setPosition(VCENTER);
		m_root->retain();
		addChild(m_root);
		m_TextRect = CCScale9Sprite::create("public/guide/blue.png");	//用于绘制测试区域的精灵
		m_TextRect->setAnchorPoint(ccp(0, 0));
		m_TextRect->setVisible(false);
		//	m_TextRect->setPreferredSize(CCSizeMake(rect.size.width, rect.size.height));	
		//	m_TextRect->setPosition(ccp(rect.origin.x, rect.origin.y));
		//	m_TextRect->setVisible(true);
		addChild(m_TextRect, 99999);
		m_mapData = DataCenter::sharedData()->getMap()->getCurrWarMap();

		m_LayerColor = CCLayerColor::create(ccc4(0,0,0,250));
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		m_LayerColor->setContentSize(size);
		m_LayerColor->setVisible(false);
		this->addChild(m_LayerColor,-1);
		return true;
	}
	return false;
}

void CombatGuideLayer::initScene( WarScene*scene )
{
	m_Scene = scene;
	m_mapData = DataCenter::sharedData()->getMap()->getCurrWarMap();
	m_MapLayer = m_Scene->getWarMapLayer();
	m_AliveLayer = m_Scene->getWarAliveLayer();
}

void CombatGuideLayer::ClearGuideLayer()
{
	m_root->removeAllChildren();
	m_LayerColor->setVisible(false);
	m_VecRect.clear();
	m_MapLayer->CancelGuide();
	m_RenderTexture = nullptr;
}
//根据图片绘制高亮区域
void CombatGuideLayer::RenderTextureinit(CCRect Rect,const char* path,const char* cover /*=""*/,bool ClearColor /*=true*/) 
{ 
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize(); 
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	if (!m_RenderTexture)
	{
		m_RenderTexture = CCRenderTexture::create(visibleSize.width, visibleSize.height, kCCTexture2DPixelFormat_RGBA8888); 
		m_RenderTexture->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2)); 
		m_root->addChild(m_RenderTexture,Background_Z); 
	}
	CCSprite* pMask = CCSprite::create(path); 
	if (!pMask)
	{
		CCLOG("[ *ERROR ] CombatGuideLayer::RenderTextureinit pMask NULL");
		return ;
	}
	pMask->setPosition(ccp(Rect.origin.x,Rect.origin.y)); 
	pMask->setAnchorPoint(ccp(0,0)); 
	pMask->setScaleX(Rect.size.width/pMask->getContentSize().width); 
	pMask->setScaleY(Rect.size.height/pMask->getContentSize().height); 
	ccBlendFunc blend; 
	blend.src = GL_ZERO; 
	blend.dst = GL_ONE_MINUS_SRC_ALPHA; 
	pMask->setBlendFunc(blend);
	if (ClearColor)m_RenderTexture->clear(0,0,0,0.5f);				//最后一个值为透明度
	m_RenderTexture->begin(); 
	pMask->visit();
	m_RenderTexture->end();

	if (strcmp(cover,""))
	{
		CCSprite* sp_cover = CCSprite::create(cover);
		sp_cover->setPosition(ccp(Rect.origin.x+Rect.size.width/2,Rect.origin.y+Rect.size.height/2));
		m_root->addChild(sp_cover,Background_Z);
	}
} 
//创建一个指向p点方向为direction的精灵path
CCSprite* CombatGuideLayer::PointSprite(CCPoint&p,int direction,int spritetype)
{
	string path = "public/guide/newhand.png";
	if (spritetype==Arraw_Type)
		path = "public/guide/arrows.png";
	CCSprite* point_sp = CCSprite::create(path.c_str());				//精灵默认方向向右	
	point_sp->setAnchorPoint(ccp(1,0.5));
	switch (direction)													
	{
	case D_Up:
		{
			point_sp->setRotation(-90);
			point_sp->setPosition(ccpAdd(p,ccp(0,-40)));
		}break;
	case D_Down:
		{
			point_sp->setRotation(90);
			point_sp->setPosition(ccpAdd(p,ccp(0,40)));
		}
		break;
	case D_Left:
		{
			point_sp->setRotation(180);
			point_sp->setPosition(ccpAdd(p,ccp(40,0)));
		}
		break;
	case D_Right:
		{
			point_sp->setPosition(ccpAdd(p,ccp(-40,0)));
		}
		break;
	case D_Left_Down:
		{
			point_sp->setRotation(45);
			point_sp->setPosition(ccpAdd(p,ccp(-40,40)));
		}
		break;
	case D_Right_Down:
		{
			point_sp->setRotation(135);
			point_sp->setPosition(ccpAdd(p,ccp(40,40)));	
		}
		break;
	case D_Left_Up:
		{
			point_sp->setRotation(-45);
			point_sp->setPosition(ccpAdd(p,ccp(-40,-40)));
		}
		break;
	case D_Right_Up:
		{
			point_sp->setRotation(-135);
			point_sp->setPosition(ccpAdd(p,ccp(40,-40)));
		}
		break;
	default:
		break;
	}
	point_sp->setPosition(p); 
	m_root->addChild(point_sp,PointSp_Z);
	return point_sp;
}
//在触摸范围内返回false让下层处理否则返回true吞噬触摸
bool CombatGuideLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint point = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	point = m_root->convertToNodeSpace(point);
	//这个触摸的区域可以是一个数组,在多个区域内触摸都是可以通过的。
	if (!m_VecRect.size())
		return false;
	for (vector<CCRect>::iterator iter = m_VecRect.begin();iter != m_VecRect.end();iter++)
	{
		if ((*iter).containsPoint(point))
		{
			if (m_Step->getType() == ImageText_Type)
			{
				DataCenter::sharedData()->getCombatGuideMg()->NextStep();
				return true;
			}
			return false;
		}
	}
	return true;
}
//容错性判断上一级已经处理,执行有关于地图类相关的引导操作时,进行锁移动层处理。
void CombatGuideLayer::setGuideStep(CombatGuideStep* step)
{
	if (step)
	{
		m_Step = step;
		ResponseRect(m_Step);					//处理响应区域(通知管理器进入下一步的引导)
	}else{CCLOG("[ *ERROR ]CombatGuideLayer::setGuideStep");}
}
CombatGuideStep* CombatGuideLayer::getGuideStep(){return m_Step;}

cocos2d::CCPoint CombatGuideLayer::getPointByMapGrid( int grid )
{
	CCPoint p = m_mapData->getPoint( grid );							//得到绝对世界坐标系的店
	CCPoint pWorld = m_AliveLayer->convertToWorldSpace(p);				//根据父节点的位置得到点当前相对世界坐标的点
	CCPoint GuidePoint = m_root->convertToNodeSpace(pWorld);			//根据当前世界坐标上的点转化为节点上的点
	return GuidePoint;
}

void CombatGuideLayer::ResponseRect(CombatGuideStep* step)
{
	switch (step->getType())
	{
	case AliveMove_Type:
		{
			SingleGrid(step);
		}break;
	case UI_Type:
		{
			UIGuide(step);
		}break;
	case ImageText_Type:
		{
			CCSize size  = CCDirector::sharedDirector()->getWinSize();
			m_VecRect.push_back(CCRect(0,0,size.width,size.height));			//文字类引导时区域是整个屏幕)
			ImageTextGuide(step);												//图片文字内容处理
		}break;
	case CallAalive_Type:
		{
			CallAlive(step);
		}break;
	case Batter_Type:	//在UI操作的基础上停掉必杀技能的效果。
		{
			UIGuide(step);
		}break;
	default:
		break;
	}
}

void CombatGuideLayer::ImageArray(CombatGuideStep* step)
{
	if (step->m_imageData.empty())
		return;
	for(unsigned int i=0; i<step->m_imageData.size(); i++)
	{
		ImageData& imagedata = step->m_imageData[i];
		if (imagedata.isSpine)
		{
			if (imagedata.SendMsg)
				NOTIFICATION->postNotification(COST_AREA,CCInteger::create(imagedata.SendMsg));
			char bg_path[60] = {0};
			sprintf(bg_path,"888%d",imagedata.spineID);
			spSkeletonData* data = nullptr;
			SpData* pData = DataCenter::sharedData()->getWar()->getSpineData(bg_path);
			if (pData)
			{
				data = pData->first;
			}else{
				CCLOG("[ *ERROR ] CombatGuideLayer::ImageArray roleId=%s",bg_path);
				char path[60] = {0};
				sprintf(path,"storyImage/Spine/888%d",imagedata.spineID);
				data = LoadSpineData::create()->loadSpineImmediately(bg_path,path);
			}
			SkeletonAnimation*Animation = SkeletonAnimation::createWithData(data);
			Animation->setPosition(imagedata.pos);
			Animation->setAnimation(0,"stand",true);
			if (imagedata.bFlipX)
				Animation->setScaleX(-1);
			Animation->setRotation(imagedata.iRotation);
			m_root->addChild(Animation, imagedata.iZorder);
		}else{
			initguideImage(step->m_imageData[i]);
		}
	}
}

void CombatGuideLayer::initguideImage( ImageData& data )
{
	CCSprite* pSprite = CCSprite::create(data.sFile.c_str());
	pSprite->setPosition(data.pos);
	pSprite->setScale(data.fScale);
	pSprite->setFlipX(data.bFlipX);
	pSprite->setFlipY(data.bFlipY);
	pSprite->setRotation(data.iRotation);
	if (data.SendMsg)
		NOTIFICATION->postNotification(COST_AREA,CCInteger::create(data.SendMsg));
	m_root->addChild(pSprite, data.iZorder);
	if(data.iDir == 1)
	{
		pSprite->runAction(CCRepeatForever::create(CCSequence::create(
			CCMoveBy::create(0.4f, ccp(90, 0))
			,CCMoveBy::create(0.4f, ccp(-90, 0)),
			NULL)));
	}
	else if(data.iDir == 2)
	{
		pSprite->runAction(CCRepeatForever::create(CCSequence::create(
			CCMoveBy::create(0.4f, ccp(0, 90))
			,CCMoveBy::create(0.4f, ccp(0, -90)),
			NULL)));
	}
}

void CombatGuideLayer::ImageTextGuide(CombatGuideStep* step)
{
	if(step->getBlackBottom())
	{
		CCSprite* bg = CCSprite::create("public/duihuakuang (2).png");
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		bg->setPosition(ccp(size.width/2,bg->getContentSize().height/2));
		//CCSprite* bg2 = CCSprite::create("public/duihuakuang (2).png");
		//bg2->setFlipY(true);
		//bg2->setPosition(ccp(size.width/2,size.height-bg->getContentSize().height/2));
		//m_root->addChild(bg2);
		m_root->addChild(bg, 2);
	}
	if (strcmp("",step->getName().c_str()))		//剧情角色名称
	{
		CCSprite* mask = CCSprite::create("warScene/mask2.png");
		mask->setAnchorPoint(ccp(0,1));
		mask->setPosition(step->m_NamePoint-ccp(mask->getContentSize().width/5,-mask->getContentSize().height/4));
		m_root->addChild(mask, 3);
		CCLabelTTF* name = CCLabelTTF::create(step->getName().c_str(),"Arial",30);
		name->setHorizontalAlignment(kCCTextAlignmentLeft);
		name->setAnchorPoint(ccp(0,1));
		name->setPosition(step->m_NamePoint);
		m_root->addChild(name, 4);
	}
	ImageArray(step);
	if (strcmp("",step->getDescribe().c_str()))	//剧情描述内容
	{
		CCLabelTTF* describe = CCLabelTTF::create(step->getDescribe().c_str(),"Arial",step->getsize());
		describe->setHorizontalAlignment((CCTextAlignment)(step->getDescribeAligment()));
		describe->setAnchorPoint(step->m_DescribeAnchor);
		describe->setDimensions(step->m_DescribeDimensions);
		describe->setPosition(step->m_Despoint);
		describe->setColor(ccc3(step->getDescribeFontColor(), step->getDescribeFontColor(), step->getDescribeFontColor()));
		m_root->addChild(describe, 5);
	}
	if (step->getCaptain())						//是否显示主帅标记(出一个标记的横向箭头)
	{
		CCSprite* arrows = CCSprite::create("public/guide/arrows.png"); 
		arrows->setAnchorPoint(ccp(0.8f,0.5f));
		WarAlive* alive = DataCenter::sharedData()->getWar()->getAliveByGrid(C_CAPTAINSTAND);
		CCPoint p = alive->getActObject()->getPosition();									//得到点阵图坐标
		CCPoint point(p.x-GRID_WIDTH,p.y+GRID_HEIGHT);										//得到偏移坐标
		CCPoint point_offset = m_root->convertToNodeSpace(m_AliveLayer->convertToWorldSpace(point));					//在warAliveLayer上的点都会默认减去地图的一半,因此直接转化世界坐标就可以，因为m_root的关系，这里还是转为相对坐标
		arrows->setPosition(point_offset);
		CCMoveTo* mt = CCMoveTo::create(0.5f,ccp(point_offset.x+GRID_WIDTH/2,point_offset.y));
		CCMoveTo* mt2 = CCMoveTo::create(0.35f,point_offset);
		arrows->runAction(CCRepeatForever::create(CCSequence::create(mt,mt2,NULL)));
		m_root->addChild(arrows, 6);
	}
	m_LayerColor->setVisible(step->getBlackLayer());
	if (step->getReset())						//是否重置武将处理
	{
		m_AliveLayer->removeMessage();														//释放掉触摸消息
		CCMoveTo* mt = CCMoveTo::create(0.2f,ccp(MAP_MINX(DataCenter::sharedData()->getMap()->getCurrWarMap()),0));	//飞到最右侧
		m_Scene->getMoveLayer()->runAction(mt);
		CCArray* arr = DataCenter::sharedData()->getWar()->getHeros();
		CCObject* obj = nullptr;
		vector<WarAlive*>VecAlive;
		CCARRAY_FOREACH(arr,obj)
		{
			WarAlive* alive = (WarAlive*)obj;
			if (alive->getCaptain())														//重置我方数据
				continue;
			VecAlive.push_back(alive);
			if (alive->getHp()<=0||!alive->getBattle()||!alive->getActObject())
				continue;
			CCPoint p = m_mapData->getPoint(INVALID_GRID);
			alive->getMoveObj()->setPosition(p);
			alive->getActObject()->setPosition(p);											//在视野外进行死亡处理
			if (!alive->getEnemy()&&alive->getCriAtk())
				NOTIFICATION->postNotification(SKILLEND,alive);
			alive->getActObject()->AliveDie();
			alive->getActObject()->setReset(true);
			alive->setActObject(nullptr);
		}
		for(WarAlive*alive:VecAlive)
		{
			bool jump = false;
			for (auto compel:step->m_VecCompel)
			{
				if (alive->getModel() == compel.model)
				{
					DataCenter::sharedData()->getWar()->initAlive(alive);
					m_AliveLayer->createAlive(alive);
					m_AliveLayer->AddAliveToGrid(alive,compel.grid);
					jump = true;
					break;
				}
			}
		}
	}
	if (step->getAddCost())
	{
		NOTIFICATION->postNotification(CHANGECOST,CCFloat::create(-10000));//置空处理
		NOTIFICATION->postNotification(CHANGECOST,CCFloat::create(step->getAddCost()));
	}
}

void CombatGuideLayer::SingleGrid(CombatGuideStep* step)
{
	CCPoint p_Begin		= getPointByMapGrid(step->getBegingrid());
	CCPoint p_Finish	= getPointByMapGrid(step->getFinishgrid());
	CCRect BeginRect	(p_Begin.x-GRID_WIDTH/2,p_Begin.y-GRID_HEIGHT/2,GRID_WIDTH,GRID_HEIGHT);
	CCRect FinishRect	(p_Finish.x-GRID_WIDTH/2,p_Finish.y-GRID_HEIGHT/2,GRID_WIDTH,GRID_HEIGHT);
	m_MapLayer->OpenGuide(step->getFinishgrid());
	m_VecRect.push_back(BeginRect);

	CCSprite* head_sp = PointSprite(p_Begin,D_Left_Up,Hand_Type);	
	CCPlace* plc = CCPlace::create(head_sp->getPosition());
	CCDelayTime* dle = CCDelayTime::create(0.50f);
	CCDelayTime* dle2 = CCDelayTime::create(0.50f);
	CCScaleTo* h_sct = CCScaleTo::create(0.25f,0.85f);
	CCMoveTo* h_mt = CCMoveTo::create(1.0f,p_Finish);
	CCScaleTo* h_sct2 = CCScaleTo::create(0.25f,1.0f);
	CCSequence* h_sqe = CCSequence::create(dle2,h_sct,h_mt,h_sct2,dle,plc,NULL);
	head_sp->runAction(CCRepeatForever::create(h_sqe));

	CCSprite* Arraw_sp = PointSprite(p_Finish,D_Down,Arraw_Type);
	CCScaleTo* a_sc1 = CCScaleTo::create(0.3f,0.6f);
	CCMoveBy* a_mb1 = CCMoveBy::create(0.3f,ccp(0,30));

	CCScaleTo* a_sc2 = CCScaleTo::create(0.3f,0.7f);
	CCMoveBy* a_mb2 = CCMoveBy::create(0.3f,ccp(0,-30));

	CCSpawn* a_spa1 = CCSpawn::create(a_sc1,a_mb1,NULL);
	CCSpawn* a_spa2 = CCSpawn::create(a_sc2,a_mb2,NULL);
	Arraw_sp->runAction(CCRepeatForever::create(CCSequence::create(a_spa1,a_spa2,NULL)));
}

bool CombatGuideLayer::getUIRect( CCRect& Rect , int uiCode)
{
	WarControl* controlLayer = m_Scene->getWarUI();
	if (!controlLayer)
	{
		CCLOG("[ *ERROR ] CombatGuideLayer::UIGuide controlLayer Is NULL");
		return false;
	}
	CCNode* UINode = nullptr;
	switch (uiCode)
	{
	case generalBtn:{ UINode = controlLayer->getLaout()->getChildByTag(CL_BtnLayout1)->getChildByTag(CL_HeroNode)->getChildByTag(CL_Btn); 
					}break;
	case skill2Btn:{ UINode = controlLayer->getLaout()->getChildByTag(CL_BtnLayout2)->getChildByTag(CL_HeroNode)->getChildByTag(CL_Btn); 
				   }break;
	case skill3Btn:{ UINode = controlLayer->getLaout()->getChildByTag(CL_BtnLayout3)->getChildByTag(CL_HeroNode)->getChildByTag(CL_Btn); 
				   }break;
	case skill4Btn:{ UINode = controlLayer->getLaout()->getChildByTag(CL_BtnLayout4)->getChildByTag(CL_HeroNode)->getChildByTag(CL_Btn); 
				   }break;
	case skill5Btn:{ UINode = controlLayer->getLaout()->getChildByTag(CL_BtnLayout5)->getChildByTag(CL_HeroNode)->getChildByTag(CL_Btn); 
				   }break;
	default:
		break;
	}
	if (UINode)
	{
		CCRect UIRect = UINode->boundingBox();		//实际的触摸区域要比UI控件的区域小,下一步响应的方式也应该在功能处
		CCPoint p = controlLayer->getLaout()->convertToNodeSpace(UINode->getParent()->convertToWorldSpace(UIRect.origin));
		Rect = CCRect(p.x+5,p.y+5,UIRect.size.width-5,UIRect.size.height-5);
	}else{
		CCLOG("[ *ERROR ] CombatGuideLayer::UIGuide UINode Is NULL");
		return false;
	}
	return true;
}

void CombatGuideLayer::UIGuide(CombatGuideStep* step)
{
	CCRect Rect;
	if (!getUIRect(Rect,step->getUiType()))
	{
		CCLOG("[ *ERROR ] CombatGuideLayer::UIGuide");
		return;
	}
	m_VecRect.push_back(Rect);
	CCSprite* pSprite = CCSprite::create("public/guide/dianji1.png");
	pSprite->setPosition(ccp(Rect.origin.x+pSprite->getContentSize().width/2-14 ,Rect.origin.y+Rect.size.height/2));
	m_root->addChild(pSprite);
	CCPoint point = ccpAdd(Rect.origin,ccp(Rect.size.width/2,Rect.size.height));
	CCSprite* head_sp = PointSprite(point,D_Down,Hand_Type);
	CCDelayTime* dly = CCDelayTime::create(0.3f);
	CCMoveBy* mb1 = CCMoveBy::create(0.5f,ccp(0,-20));
	CCMoveBy* mb2 = CCMoveBy::create(0.3f,ccp(0,20));
	head_sp->runAction(CCRepeatForever::create(CCSequence::create(dly,mb1,mb2,NULL)));
}
//召唤武将类引导处理
void CombatGuideLayer::CallAlive( CombatGuideStep* step )
{
	CCRect Rect;
	if (!getUIRect(Rect,step->getUiType()))
	{
		CCLOG("[ *ERROR ] CombatGuideLayer::UIGuide");
		return;
	}
	m_VecRect.push_back(Rect);
	CCPoint p_Finish		= getPointByMapGrid(step->getFinishgrid())/*m_mapData->getPoint(step->getFinishgrid())*/;
	CCRect FinishRect	(p_Finish.x-GRID_WIDTH/2,p_Finish.y-GRID_HEIGHT/2,GRID_WIDTH,GRID_HEIGHT);
	m_MapLayer->OpenGuide(step->getFinishgrid());

	CCSprite* pSprite = CCSprite::create("public/guide/dianji1.png");
	pSprite->setPosition(ccp(Rect.origin.x+pSprite->getContentSize().width/2-14 ,Rect.origin.y+Rect.size.height/2));
	m_root->addChild(pSprite);

	CCPoint point = pSprite->getPosition();
	CCSprite* head_sp = PointSprite(point,D_Left_Up,Hand_Type);													//

	CCPlace* plc = CCPlace::create(head_sp->getPosition());
	CCDelayTime* dle = CCDelayTime::create(0.50f);
	CCDelayTime* dle2 = CCDelayTime::create(0.50f);
	CCScaleTo* h_sct = CCScaleTo::create(0.25f,0.85f);
	CCMoveTo* h_mt = CCMoveTo::create(1.0f,p_Finish);
	CCScaleTo* h_sct2 = CCScaleTo::create(0.25f,1.0f);
	CCSequence* h_sqe = CCSequence::create(dle2,h_sct,h_mt,h_sct2,dle,plc,NULL);
	head_sp->runAction(CCRepeatForever::create(h_sqe));

	CCSprite* Arraw_sp = PointSprite(p_Finish,D_Down,Arraw_Type);
	CCScaleTo* a_sc1 = CCScaleTo::create(0.3f,0.6f);
	CCMoveBy* a_mb1 = CCMoveBy::create(0.3f,ccp(0,30));

	CCScaleTo* a_sc2 = CCScaleTo::create(0.3f,0.7f);
	CCMoveBy* a_mb2 = CCMoveBy::create(0.3f,ccp(0,-30));

	CCSpawn* a_spa1 = CCSpawn::create(a_sc1,a_mb1,NULL);
	CCSpawn* a_spa2 = CCSpawn::create(a_sc2,a_mb2,NULL);
	Arraw_sp->runAction(CCRepeatForever::create(CCSequence::create(a_spa1,a_spa2,NULL)));
}