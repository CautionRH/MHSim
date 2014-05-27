#pragma once

class HeroStats
{
public:
	HeroStats(int attackSpeed, int criticalRating, int criticalDamage, int brutalRating, int brutalDamage) :
		_attackSpeed(attackSpeed),
		_criticalRating(criticalRating),
		_criticalDamage(criticalDamage),
		_brutalRating(brutalRating),
		_brutalDamage(brutalDamage)
	{

	} 

	int GetAttackSpeed() { return _attackSpeed; }

	int GetCritRating() { return _criticalRating; }
	
	int GetCritDamageRating() { return _criticalDamage; }
	
	int GetBrutalRating() { return _brutalRating; }

	int GetBrutalDamageRating(){ return _brutalDamage;}

private: 
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