#pragma once

#include <math.h>
#include "DamageTypes.h"

static inline double CalculateAttackSpeed(double attackSpeedPercent)
{
	double attackSpeed = 0.4 * (1.0 - exp(-3 * attackSpeedPercent));
	return attackSpeed;
}

static inline double CalculateCritPercent(double critRating)
{
	return (99.0 * critRating)/(critRating + 60.0 * 63.0 + 1);
}

static inline double CalculateBrutalPercent(double brutalRating)
{
	return (75.0 * brutalRating)/(brutalRating + 60.0 * 63.0 + 1);
}

static inline HitType GetHitType(double critRating, double brutalRating)
{
	int val = rand() % 10000 + 1;
	int critRange = 100 * CalculateCritPercent(critRating);
	if(val <= critRange) {
		int brutRange = 100 * CalculateBrutalPercent(brutalRating);;
		int brutVal = rand() % 10000 + 1;
		if(brutVal <= brutRange) {
			return HitType::Brutal;
		} else {
			return HitType::Critical;
		}
	}
	return HitType::Normal;
}

static inline double GetCritDamagePercent(int critRating)
{
	return 150 + floor((critRating / (63.0 * 0.75)));
}

static inline double GetBrutalDamagePercent(int brutalRating)
{
	return 300 + floor((brutalRating / (63.0 * 0.75)));
}