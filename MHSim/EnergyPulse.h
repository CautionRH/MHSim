#pragma once


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
			_lastAttackTimeMS = timeStamp;
			HitType hitType = GetHitType(hero->GetCritRating(), hero->GetBrutalRating());
			int dmg = 0;
			int range ( _maxDamage - _minDamage + 1);
			dmg = rand() % range + _minDamage;
			result->Result = hitType;
			switch(hitType)
			{
			case Normal:
				Logit::Instance()->LogMessage(boost::format("Cable's [%s] HIT for %d") % _skillName % dmg);
				
				break;
			case Critical:
				dmg = dmg * (1 + (GetCritDamagePercent(hero->GetCritDamageRating())/ 100.0)) * 1.40;
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

	EnergyPulse(void)
	{
		 _skillName = "Energy Pulse";
		_minDamage = 539;
		_maxDamage = 818;
		_attackPerSecond = 3.8;
		_skillTags.push_back(SkillTags::Basic);
		_skillTags.push_back(SkillTags::Ranged);
		
		_damageType = DamageTypes::Energy;
	}

	~EnergyPulse(void);
};