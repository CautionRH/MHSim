#include "Cable.h"
#include "BlisteringBolt.h"
#include "EnergyPulse.h"
#include "VortexGrenade.h"
#include "PsychicHaze.h"
#include "PsychokineticBarrier.h"

Cable::Cable(void)
{
}


Cable::~Cable(void)
{
}


bool Cable::Create()
{

	//TODO POPULATE FROM READING DATA OR SOMETHING
	_stats = new HeroStats(0.35, 3475, 2000, 2500, 1100);

	_skills.push_back((ISkill*)new BlisteringBolt());
	
	_skills.push_back((ISkill*)new VortexGrenade());
	
	_skills.push_back((ISkill*)new PsychicHaze());
	
	_skills.push_back((ISkill*)new PsychokineticBarrier());
	
	return true;
}

void Cable::DoSimulate(double timeStamp)
{
	std::vector<ISkill*>::iterator it;
	 for (it=_skills.begin(); it<_skills.end(); it++)
	 {
		 double dmg = (*it)->GetDamage(timeStamp, _stats);
	 }
}