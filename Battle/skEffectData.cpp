
#include "Battle/skEffectData.h"
#include "Battle/RoleBuffData.h"
#include <protos/common/skill_common.pb.h>

skEffectData::skEffectData()
:mEffectID(0),mEffectType(0),mUserRate(0),mImpactType(0),mImpactRate(0),mGroupPos(0)
,mChangeCost(0),mDamageRate(0),mRealHurt(0),mTargetType(0),mAreaSize(0),mGroup(0)
,mBatter(0),mRepel(0),mHurtRatio(0),mAreaType(0),mSpaceRange(0)
{}

skEffectData::~skEffectData()
{
	clearBuffData();
}

void skEffectData::readData(const protos::common::Effect* pEffect)
{
	this->setEffectID(pEffect->effectid());
	this->setGroup(pEffect->group());
	this->setGroupPos(pEffect->pos());
	this->setEffectType(pEffect->type());
	this->setDamageRate(pEffect->damage()*0.01f);
	this->setRealHurt(pEffect->hurt());
	this->setTargetType(pEffect->target());
	this->setBatter(pEffect->batter());
	this->setRepel(pEffect->repel());
	this->setHurtRatio(pEffect->erange()*0.01f);
	this->setAreaType(pEffect->mode());
	this->setSpaceRange(pEffect->distance());
	this->setAreaSize(pEffect->range());
	this->setImpactType(pEffect->pro_type());
	this->setImpactRate(pEffect->pro_rate());

	for (int i=0; i<pEffect->bufflist_size();i++)
		addBuffData(&pEffect->bufflist(i));
	this->setuserRate(pEffect->userrate());
	this->setChangeCost(pEffect->cost());
}

const std::vector<RoleBuffData*>& skEffectData::getBuffVector() const
{
	return mBuffVector;
}

void skEffectData::addBuffData( const protos::common::Buff* pBuffData )
{
	RoleBuffData* tBuffData = RoleBuffData::create();
	tBuffData->readData(pBuffData);
	tBuffData->retain();
	mBuffVector.push_back(tBuffData);
}

void skEffectData::clearBuffData()
{
	for (auto tData : mBuffVector)
	{
		CC_SAFE_RELEASE(tData);
	}
	mBuffVector.clear();
}

bool EffectSort(skEffectData Effect1,skEffectData Effect2){return Effect1.getGroupPos()<Effect2.getGroupPos();}