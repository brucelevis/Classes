/************************************************************* 
 *
 *
 *		Data : 2016.6.1
 *	
 *		Name : AreaCountInfo
 *
 *		Author : Lin_Xiancheng
 *
 *		Description : 
 *
 *
*************************************************************/

#ifndef __AreaCountInfo_H_
#define __AreaCountInfo_H_

#include <vector>
#include "cocos2d.h"
class WarAlive;

class AreaCountInfo
{
public:
	AreaCountInfo(std::vector<int>& pVector,WarAlive* pAlive);
	CC_SYNTHESIZE(WarAlive*,mAlive,Alive);		
	CC_SYNTHESIZE(int,mGrid,Grid);						//��Χ������յ�
	CC_SYNTHESIZE(bool,mEnemy,Enemy);					//�佫��Ӫ
	CC_SYNTHESIZE(bool,mBackAttack,BackAttack);			//���򹥻�
	CC_SYNTHESIZE(int,mAreaType,AreaType);				//��������
	CC_SYNTHESIZE(int,mAreaRange,AreaRange);			//���ܷ�Χ	
	CC_SYNTHESIZE(int,mDistance,Distance);				//��Χ����
	CC_SYNTHESIZE(int,mTargetType,TargetType);			//Ч��Ŀ������
public:
	void excludeCaptain();
	void excludeInvalid();
	int getRowByGrid(int pGrid);
	int getColByInfo(int pGrod);
	void addGrid(int pGrid);
	bool hasGrid(int pGrid);
	void DisperseDispose();
	void RowType(int Type);											//�����ʹ���
	void assignVector(std::vector<int>& pVector);
	const std::vector<int>& getVector()const {return mVector;}
private:
	std::vector<int>& mVector;		//��Ա����Ϊ����,���ñ���Ҫ��ʼ��(������Ҫ�������˷���������鼯��,�ṩ���Ӻ�ɾ���ĺ������ⲿ�������)
};

#endif