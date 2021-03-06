
#ifndef __BATTLEDATACENTER__
#define __BATTLEDATACENTER__
/************************************************************* 
*
*
*		Data : 2016.6.2
*	
*		Name : 
*
*		Author : Lin_Xiancheng
*
*		Description : Manage battle role data
*
*
*************************************************************/
#include <vector>

namespace google {
	namespace protobuf{
		class Message;
	}
}
namespace protos{
	namespace common{
		class Monster;
		class Hero;
		class Trap;
	}
}
using namespace std;
#define BattleData BattleSpace::BattleDataCenter::ShareBattleDataCenter()
namespace BattleSpace
{
	class TrapData;
	class HeroData;
	class MonsterData;
	class BaseRoleData;
	class BattleModel;
	class BattleDataCenter
	{
	public:
		static BattleDataCenter* ShareBattleDataCenter();
		void releaseRoleData();
	public:
		void initWordBossStage( const google::protobuf::Message *pResponse );
		void initNormalStage( const google::protobuf::Message *pResponse );
		void initPvEData( const google::protobuf::Message *pResponse);
		const  vector<HeroData*>&  getHeroVector()const	;
		const vector<MonsterData*>& getMonsterVector()const;
		const vector<MonsterData*>& getChildRoleDatas()const;
		const vector<BaseRoleData*>& getRoleDatas()const;
		const vector<HeroData*>& getPvPHeros() const;
		const vector<TrapData*>& getTraps() const;
		BaseRoleData* getChildRoleData(int pRoleID) const;
	private:
		void initRestData();
		void initBaseRoleDataVector();
		void initMonsterData(const protos::common::Monster* pData);
		void initHeroData(const protos::common::Hero* pData,bool pPvPHero = false);
		void initTrapData(const protos::common::Trap* pData);
	private:
		vector<TrapData*> mTrapVec;
		vector<HeroData*> mHeroVec;
		vector<HeroData*> mPvPHeros;
		vector<MonsterData*>mMonsterVec;
		vector<MonsterData*>mChildRoleVec;
		vector<BaseRoleData*>mBaseRoleData;
		BattleDataCenter();
		static BattleDataCenter* mDataControl;
		class SingletonDestroy
		{
		public :
			~SingletonDestroy()
			{
				if (mDataControl != nullptr )
				{
					delete mDataControl;
					mDataControl = nullptr ;
				}
			}
		};
		static SingletonDestroy mDestroy;
	};
};
#endif