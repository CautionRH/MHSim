#pragma once

#include "ISkill.h"
#include "HeroStats.h"
#include "StatCalcs.h"
 
#include "Logit.h"
class VortexGrenade : ISkill
{
public:
		
	AttackResult* GetDamage(double timeStamp, HeroStats *hero)
	{
		double adjusted = 500;//(1.0 / ((1 + CalculateAttackSpeed(hero->GetAttackSpeed())) * _attackPerSecond)) * 1000;
		AttackResult* result = new AttackResult();
		if(_lastCastTimeMS == 0 || (_lastCastTimeMS + _skillDurationMS) < timeStamp) 
		{
			result->Result = HitType::Cast;
			result->ResourceCost = _resourceCost;
			_lastCastTimeMS = timeStamp;
			Logit::Instance()->LogMessage(boost::format("Cable casts [%s]") % _skillName);
			::Sleep(_castTimeMS);
		}else if((_lastAttackTimeMS + adjusted) <= timeStamp) {
			_lastAttackTimeMS = timeStamp;
			HitType hitType = GetHitType(hero->GetCritRating(), hero->GetBrutalRating());
			int dmg = 0;
			int modMin = _minDamage;
			int modMax = _maxDamage;
			
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

	VortexGrenade(void)
	{
		 _skillName = "Vortex Grenade";
		_minDamage = 1884;
		_maxDamage = 1884;
		_attackPerSecond = 2.0;
		_skillTags.push_back(SkillTags::Area);
		_skillTags.push_back(SkillTags::Ranged);
		_damageType = DamageTypes::Energy;
		_castTimeMS = 250;
		_skillDurationMS = 9200;
	}

	~VortexGrenade(void);
};