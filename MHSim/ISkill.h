/*
-----------------------------------------------------------------------------
This source file is part of MHSim
For the lastest info, visit https://github.com/CautionRH/MHSim/

COPYRIGHT (C) 2014 Russ Harrington

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
-----------------------------------------------------------------------------
*/

#ifndef _I_SKILL_H__
#define _I_SKILL_H__

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
	virtual void PrintReport() = 0;
protected:
	std::string _skillName;
	std::vector<SkillTags> _skillTags;

	double _resourceCost;
	double _minDamage;
	double _maxDamage;
	double _totalDamage;
	double _numHits;
	double _hitDamage;
	double _numCrits;
	double _critDamage;
	double _numBrutals;
	double _brutalDamage;
	double _attackPerSecond;
	double _lastAttackTimeMS;
	double _skillDurationMS;
	double _castTimeMS;
	double _numCasts;
	double _lastCastTimeMS;
	DamageTypes _damageType;


};

#endif