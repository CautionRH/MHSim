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

#ifndef _I_HERO_H__
#define _I_HERO_H__


#include <iostream>
#include <vector>

#include "ISkill.h"
#include "IEquipment.h"

using namespace std;

class IHero
{
public:
	virtual bool Create() = 0;
	virtual void DoSimulate(double timeStamp) = 0;
	void AddSkill(ISkill* skill) { _skills.push_back(skill);}
protected:

	std::wstring _heroName;
	std::vector<ISkill*> _skills;
	std::vector<IEquipment*> _equipment;

	double _totalSimulatedDamage;
	HeroStats* _stats;



};

#endif