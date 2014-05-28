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

#ifndef _HERO_STATS_H__
#define _HERO_STATS_H__

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

	void UpdateAttackSpeed(double attackSpeed) { _attackSpeed = attackSpeed; }
	void UpdateCritRating(double criticalRating) { _criticalRating = criticalRating; }
	void UpdateCritDamageRating(double criticalDamage) { _criticalDamage = criticalDamage; }
	void UpdateBrutalRating(double brutalRating) {  _brutalRating = brutalRating; }
	void UpdateBrutalDamageRating(double brutalDamage){ _brutalDamage = brutalDamage;}


	HeroStats* Clone(){return new HeroStats(*this);}
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

#endif