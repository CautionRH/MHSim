#pragma once

#include "ISkill.h"
#include "HeroStats.h"
#include "StatCalcs.h"
 
#include "Logit.h"
class VortexGrenade : ISkill
{
public:
		
	double GetDamage(double timeStamp, HeroStats *hero)
	{
		double adjusted = 500;//(1.0 / ((1 + CalculateAttackSpeed(hero->GetAttackSpeed())) * _attackPerSecond)) * 1000;
		if((_lastAttackTimeMS + adjusted) <= timeStamp)
		{
			_lastAttackTimeMS = timeStamp;
			HitType hitType = GetHitType(hero->GetCritRating(), hero->GetBrutalRating());
			int dmg = 0;
			int modMin = _minDamage;
			int modMax = _maxDamage;
			
			int range ( _maxDamage - _minDamage + 1);
			dmg = rand() % range + _minDamage;
			
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
			return dmg;
		}
		return 0;
	}

	VortexGrenade(void)
	{
		 _skillName = "Vortex Grenade";
		_minDamage = 1884;
		_maxDamage = 1884;
		_attackPerSecond = 2.0;
		_skillTags.push_back(SkillTags::Area);
		_skillTags.push_back(SkillTags::Ranged);
		_damageType = DamageTypes::Energy;
	}

	~VortexGrenade(void);
};