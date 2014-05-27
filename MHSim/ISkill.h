#pragma once

#include <iostream>
#include <vector>

#include "SkillTags.h"
#include "HeroStats.h"
#include "DamageTypes.h"
#include "AttackResult.h"

using namespace std;

class ISkill
{
public:
	virtual AttackResult* GetDamage(double timeStamp, HeroStats* stats) = 0;
protected:
	std::string _skillName;
	std::vector<SkillTags> _skillTags;

	double _resourceCost;
	double _minDamage;
	double _maxDamage;
	double _attackPerSecond;
	double _lastAttackTimeMS;
	double _skillDurationMS;
	double _castTimeMS;
	double _lastCastTimeMS;
	DamageTypes _damageType;


};