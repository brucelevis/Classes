﻿#pragma once

/******************************************************
*文件名称:	LoginScene.h
*编写日期:	2016-6-29-16:51
*编写作者:	YPF
*功能描述:	登录场景
*******************************************************/

#include "AppUI.h"
#include "ApplicationDefine.h"
#include "update/CUpdateData.h"
#include "UserDefaultData.h"
#include "net/CNetClient.h"

class BaseLayer;

//登录类型，会被记录
enum LoginType
{
	LoginTypeNull					=	0,	//未选择类型
	LoginTypeTourist				= 1,	//游客
	LoginTypeFacebook			= 2,	//facebook
	LoginTypeGoogle				= 3,	//google
};


class LoginScene: public CScene
{
public:
	LoginScene();
	~LoginScene();
	DEFINE_SCENE_CLASS(LoginScene);

	virtual void onCreate();
	virtual void onEnter();
	virtual void onExit();

public:
	static GateServer getGateServer();

private:
	void showWarning();
	void callBackForInit();

private:
	//不同发布平台获取不同的操作层
	BaseLayer *getLoginLayerWithGamePlatfom();
};
