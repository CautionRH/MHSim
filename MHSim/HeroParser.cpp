#include "HeroParser.h"
#include "pugixml\pugixml.hpp"
#include "Cable.h"

//--------------------------------------------------------------------------------
// Global static pointer to enusre a single instance of the class
//--------------------------------------------------------------------------------
HeroParser* HeroParser::_instance = NULL;



HeroParser::HeroParser(void)
{
}


//--------------------------------------------------------------------------------
// Function: Instance
// Description: Singleton access function
// Date: 2014-05-06
//--------------------------------------------------------------------------------
HeroParser* HeroParser::Instance()
{ 
    if(!_instance) {
        _instance = new HeroParser;
	}

	return _instance;
}


//--------------------------------------------------------------------------------
// Function:
// Description:
// Date: 2014-05-06
//--------------------------------------------------------------------------------

IHero* HeroParser::LoadHero(std::string xmlFile) 
{
	pugi::xml_document doc;
	if(!doc.load_file(xmlFile.c_str())) return NULL;

	if(doc.child("hero").attribute("id").value() == "Cable")
	{
		return (IHero*)CreateCable(doc);
	}
	return NULL;
}


Cable* HeroParser::CreateCable(pugi::xml_document doc)
{
	Cable* cable = new Cable();
	cable->Create();
	pugi::xml_node skills = doc.child("hero").child("skills");

	for (pugi::xml_node_iterator it = skills.begin(); it != skills.end(); ++it)
    {
		if(it->attribute("id").value() == "vortex_grenade") {
			cable->AddSkill((ISkill*)new VortexGrenade());
		} else if (it->attribute("id").value() == "blistering_bolt") {
			cable->AddSkill((ISkill*)new BlisteringBolt());
		} else if (it->attribute("id").value() == "energy_pulse") {
			cable->AddSkill((ISkill*)new EnergyPulse());
		} else if (it->attribute("id").value() == "psychic_haze") {
			cable->AddSkill((ISkill*)new PsychicHaze());
		} else if (it->attribute("id").value() == "psychokinetic_barrier") {
			cable->AddSkill((ISkill*)new PsychokineticBarrier());
		}
	}

}