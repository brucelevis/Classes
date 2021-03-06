﻿#ifndef _MOVEDISPOSE_
#define _MOVEDISPOSE_

#include "AppUI.h"
/************************************************************* 
 *
 *
 *		Data : 2016.4.19
 *	
 *		Name : 
 *
 *		Author : Lin_Xiancheng
 *
 *		Description : 移动策略(当前没有用)
 *
 *
 *************************************************************/
namespace BattleSpace{
	class BaseRole;
	class MoveRule : public CCObject
	{
	public:
		MoveRule();
		~MoveRule();
		virtual bool init();
		CREATE_FUNC(MoveRule);
		int getMonsterMoveGrid(BaseRole* alive);
		int CountMoveGrid(BaseRole* alive,int grid);
		int MoveJudge(BaseRole* alive,int grid);				//用于判断是否可以移动，多格站位处理
		int FrontBack(BaseRole* alive,int range,bool enemy);
		int monsterMove(BaseRole* target);
		bool MonstMoveExcute(BaseRole* monster);
		int getCurrRandomGrid(int grid,bool hasAlive = false);
	private:
	};
};

#endif