#pragma once

#include <iostream>
#include <vector>

#include "SkillTags.h"

using namespace std;

class ISkill
{
public:
	virtual double GetDamage(double timeStamp) = 0;
protected:
	std::wstring _skillName;
	std::vector<SkillTags> _skillTags;
};