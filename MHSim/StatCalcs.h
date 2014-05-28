
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

#include <Windows.h>

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