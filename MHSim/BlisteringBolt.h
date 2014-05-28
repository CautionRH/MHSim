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

#pragma once

#include <time.h>

#include "ISkill.h"
#include "SkillTags.h"
#include "StatCalcs.h"
#include "IHero.h"

#include "Logit.h"

class BlisteringBolt : ISkill
{
public:
	
	AttackResult* GetDamage(double timeStamp, HeroStats *hero)
	{
		double adjusted = (1.0 / ((1 + CalculateAttackSpeed(hero->GetAttackSpeed())) * _attackPerSecond)) * 1000;
		AttackResult* result= new AttackResult();
		if((_lastAttackTimeMS + adjusted) <= timeStamp)
		{
			_lastAttackTimeMS = timeStamp;
			HitType hitType = GetHitType(hero->GetCritRating(), hero->GetBrutalRating());
			int dmg;
			int range ( _maxDamage - _minDamage + 1);
			dmg = rand() % range + _minDamage;
			result->Result = hitType;
			switch(hitType)
			{
			case Normal:
				Logit::Instance()->LogMessage(boost::format("Cable's [%s] HIT for %d") % _skillName % dmg);
				break;
			case Critical:
				dmg = dmg * (1 + (GetCritDamagePercent(hero->GetCritDamageRating())/ 100.0));
				Logit::Instance()->LogMessage(boost::format("Cable's [%s] CRIT for %d") % _skillName % dmg);
				break;
			case Brutal:
				dmg = dmg * (1 + (GetBrutalDamagePercent(hero->GetBrutalDamageRating()) / 100.0));
				Logit::Instance()->LogMessage(boost::format("Cable's [%s] BRUTALED for %d") % _skillName % dmg);
				break;
			}
			result->Damage = dmg;
		}
		return result;
	}

	BlisteringBolt(void)
	{
		 _skillName = "Blistering Bolt";
		_minDamage = 1837;
		_maxDamage = 2755;
		_attackPerSecond = 3.0;
		_skillTags.push_back(SkillTags::Basic);
		_skillTags.push_back(SkillTags::Ranged);
		_damageType = DamageTypes::Energy;
	}

	~BlisteringBolt(void);

};

