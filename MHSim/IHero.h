#pragma once

#include "ISkill.h"

#include <iostream>
#include <vector>

using namespace std;

class IHero
{
public:
	virtual bool Create() = 0;
	virtual void DoSimulate(double timeStamp) = 0;

protected:

	std::wstring _heroName;
	std::vector<ISkill*> _skills;


	int _attackSpeed;
	int _block;
	int _defenseRating;
	int _dodgeRating;
	int _criticalRating;
	int _criticalDamage;
	int _brutalRating;
	int _brutalDamage;
	int _hitPoints;
	int _resources;
	int _durability;
	int _strength;
	int _fighting;
	int _speed;
	int _energy;
	int _intelligence;
};

