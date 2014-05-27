#pragma once

#include "DamageTypes.h"

class AttackResult
{
public:
	AttackResult(){ Damage = 0; ResourceCost = 0; }
	double Damage;
	double ResourceCost;
	HitType Result;

};