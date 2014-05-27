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

	double _totalSimulatedDamage;

	HeroStats* _stats;
};

