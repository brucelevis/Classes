﻿#ifndef _WARHANDLE_H_
#define _WARHANDLE_H_
#include <string>
#include "AppUI.h"
/************************************************************************/
/*         
		用于辅助warScene显示使用			//  [9/9/2014 xc_lin]
*/
/************************************************************************/
namespace BattleSpace{

	class BattleRoleLayer;
	class WarControl;
	class RoleObject;
	class BaseRole;
	class BattleRoleLayer;
	class BattleRoleLayer;
	class BattleScene;


	class WarAssist : public CCObject
	{
	public:
		WarAssist();
		~WarAssist();
		virtual bool init();
		CREATE_FUNC(WarAssist);
		void setScene(BattleScene* scene);
		void DisplayBossWarning(CCObject* ob,int model = 0);
		void WinEffect(CCObject* ob);
		void playerMusic(CCObject* ob);
		void shake(CCObject* ob);
		bool lastStory();
		void ActStandExcute(CCArray* arr);
		void PlayBeginAnimation(CCObject* obj);
		void animationEvent(CCArmature *armature,MovementEventType movementType, const char *movementID);
		void frameEvent(CCBone *pBone, const char *str, int a, int b);
	private:
		void callBackForDisplayBossWarning();
	private:
		BattleRoleLayer* m_alive;			//用于存储战场的武将层
		WarControl* m_ui;
		BattleScene* m_scene;
	};
};
#endif