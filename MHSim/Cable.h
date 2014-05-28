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

#ifndef _CABLE_H__
#define _CABLE_H__

#include "IHero.h"
#include "ISkill.h"

#include "BlisteringBolt.h"
#include "EnergyPulse.h"
#include "PsychicHaze.h"
#include "PsychokineticBarrier.h"
#include "VortexGrenade.h"

class Cable : IHero
{
public:
	Cable(void);
	~Cable(void);
	bool Create();
	bool AddSkill(ISkill* skill);
	void DoSimulate(double timeStamp);
	void ReportStatistics();
	void UpdateModifiers();
protected:
	double _totalDamage;

};

#endif
