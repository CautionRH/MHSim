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

#ifndef _ENERGY_PULSE_H__
#define _ENERGY_PULSE_H__


#include "ISkill.h"
#include "HeroStats.h"
#include "StatCalcs.h"

#include "Logit.h"

class EnergyPulse : ISkill
{
public:
		
	AttackResult* GetDamage(double timeStamp, HeroStats *hero)
	{
		double adjusted = (1.0 / ((1 + CalculateAttackSpeed(hero->GetAttackSpeed())) * _attackPerSecond)) * 1000;
		AttackResult* result;
		if((_lastAttackTimeMS + adjusted) <= timeStamp)
		{
			_numCasts++;
			_lastAttackTimeMS = timeStamp;
			HitType hitType = GetHitType(hero->GetCritRating(), hero->GetBrutalRating());
			int dmg = 0;
			int range ( _maxDamage - _minDamage + 1);
			dmg = rand() % range + _minDamage;
			result->Result = hitType;
			switch(hitType)
			{
			case Normal:
				_numHits++;
				_hitDamage += dmg;
				Logit::Instance()->LogMessage(boost::format("Cable's [%s] HIT for %d") % _skillName % dmg);
				break;
			case Critical:
		
				dmg = dmg * (1 + (GetCritDamagePercent(hero->GetCritDamageRating())/ 100.0)) * 1.40;
				_numCrits++;
				_critDamage += dmg;
				Logit::Instance()->LogMessage(boost::format("Cable's [%s] CRIT for %d") % _skillName % dmg);
				break;
			case Brutal:
				dmg = dmg * (1 + (GetBrutalDamagePercent(hero->GetBrutalDamageRating()) / 100.0));
				_numBrutals++;
				_brutalDamage += dmg;
				Logit::Instance()->LogMessage(boost::format("Cable's [%s] BRUTALED for %d") % _skillName % dmg);
				break;
			}
			_totalDamage += dmg;
			result->Damage = dmg;
		}
		return result;
	}

	void PrintReport()
	{
		Logit::Instance()->LogMessage(boost::format("[%s]:\tH[%d] %d\tC[%d] %d\tB[%d] %d\tTotal[%d]: %d") % _skillName % 
													_numHits % _hitDamage %
													_numCrits % _critDamage %
													_numBrutals % _brutalDamage % 
													_numCasts %_totalDamage);
	}

	EnergyPulse(void)
	{
		 _skillName = "Energy Pulse";
		 _numCasts = 0;
		 _totalDamage = 0;
		_numHits = 0;
		 _hitDamage = 0;
		 _numCrits = 0;
		 _critDamage = 0;
		 _numBrutals = 0;
		 _brutalDamage = 0;
		_minDamage = 539;
		_maxDamage = 818;
		_attackPerSecond = 3.8;
		_skillTags.push_back(SkillTags::Basic);
		_skillTags.push_back(SkillTags::Ranged);
		
		_damageType = DamageTypes::Energy;
	}

	~EnergyPulse(void);
};

#endif