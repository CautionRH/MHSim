#include "Cable.h"
#include "BlisteringBolt.h"

Cable::Cable(void)
{
}


Cable::~Cable(void)
{
}


bool Cable::Create()
{
	std::vector<ISkill*>::iterator it;

	it = _skills.begin();
	_skills.insert(it, (ISkill*)new BlisteringBolt());
	
	return true;
}
void Cable::DoSimulate(double timeStamp)
{
	std::vector<ISkill*>::iterator it;
	 for (it=_skills.begin(); it<_skills.end(); it++)
	 {
		 double dmg = (*it)->GetDamage(timeStamp);

	 }
}