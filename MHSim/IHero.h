#pragma once


#include <iostream>

using namespace std;

class IHero
{
public:
	virtual bool Create();
	virtual void DoSimulate();

private:

	std::wstring _heroName;

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

