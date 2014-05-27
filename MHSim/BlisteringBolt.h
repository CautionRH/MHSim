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
	
	double GetDamage(double timeStamp, HeroStats *hero)
	{
		double adjusted = (1.0 / ((1 + CalculateAttackSpeed(hero->GetAttackSpeed())) * _attackPerSecond)) * 1000;
		if((_lastAttackTimeMS + adjusted) <= timeStamp)
		{
			_lastAttackTimeMS = timeStamp;
			HitType hitType = GetHitType(hero->GetCritRating(), hero->GetBrutalRating());
			int dmg = 0;
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

