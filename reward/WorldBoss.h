﻿#pragma once

#include "AppUI.h"
#include "scene/layer/LayerManager.h"
#include "net/CNetClient.h"

enum WorldBossTabType
{
	WorldBossTabNull = -1,			//null
	WorldBossTabBoss = 0,			//BOSS
	WorldBossTabRule,					//规则
	WorldBossTabShop,				//商店
	WorldBossTabMax					
};

class CWBossLayer;
class CWRuleLayer;
class CWShopLayer;
class ArmatureEventDataMgr;
class ArmatureEventData;

class CWorldBoss: public BaseLayer
{
public:
	CWorldBoss();
	~CWorldBoss();
	
	CREATE_LAYER(CWorldBoss);

    virtual bool init();
    void onEnter();
    void onExit();

	void movementCallBack(CCArmature *armature, MovementEventType type, const char *data);

	void showWorldBossEffect(int iBossId);	//BOSS出场效果

private:
	void onSwitchBtn(CCObject *pSender, bool bChecked);

	void showSelectRadioImg(int selIndex);

	void onClose(CCObject* pSender);

	void updateTableSelected(CTableView* pTable, int iSelected);

	void updateShowArea();

	void selectTabPanel(WorldBossTabType iType, bool bForce=false);

	void showBossSkill(CCNode* pSender);
	void showWorldBossEffectCallBack(CCNode* pSender);
	void showPanelUp();

	void updateFrame(float dt);
	void PlaySound_Event(int sData);


	void showShake(float fTime);
	void showShakeCallBack();
private:
	CLayout* m_ui;
	WorldBossTabType m_iType;
	CWBossLayer* m_pBossLayer;
	CWRuleLayer* m_pRuleLayer;
	CWShopLayer* m_pShopLayer;

	CCArmature* m_pArmature;
	ArmatureEventDataMgr* m_armatureEventDataMgr;
	ArmatureEventData* m_armatureEventData;
	int m_lastFrame;
};