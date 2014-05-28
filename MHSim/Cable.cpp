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

#include "Cable.h"
#include "BlisteringBolt.h"
#include "EnergyPulse.h"
#include "VortexGrenade.h"
#include "PsychicHaze.h"
#include "PsychokineticBarrier.h"
#include "AttackResult.h"
#include "IEquipment.h"

Cable::Cable(void)
{
	
}


Cable::~Cable(void)
{
}


bool Cable::Create()
{
	_totalDamage = 0;

	//TODO POPULATE FROM READING DATA OR SOMETHING
	_stats = new HeroStats(0.35, 3475, 2000, 2500, 1100);	
	return true;
}

bool Cable::AddSkill(ISkill* skill)
{
	_skills.push_back(skill);
}

void Cable::DoSimulate(double timeStamp)
{
	 HeroStats* tmpStats = _stats->Clone();
	 std::vector<ISkill*>::iterator it;
	 for (it=_skills.begin(); it<_skills.end(); it++)
	 {
		 AttackResult *dmg = (*it)->GetDamage(timeStamp, tmpStats);
		 if(dmg->Damage >0)	 _totalDamage += dmg->Damage;
	 }

	 delete tmpStats;

	 
}

void Cable::UpdateModifiers()
{
	std::vector<IEquipment*>::iterator it;
	for (it=_equipment.begin(); it<_equipment.end(); it++)
	 {
		
	 }
}

void Cable::ReportStatistics()
{
	std::vector<ISkill*>::iterator it;
	Logit::Instance()->LogMessage(L"==========================================");
	Logit::Instance()->LogMessage(L"CABLE REPORT");
	Logit::Instance()->LogMessage(boost::format("TOTAL DAMAGE: %d") % _totalDamage);
	Logit::Instance()->LogMessage(L"==========================================");
	Logit::Instance()->LogMessage(L"SKILL BREAKDOWN: ");
	for (it=_skills.begin(); it<_skills.end(); it++)
	{
		(*it)->PrintReport();
	}
}