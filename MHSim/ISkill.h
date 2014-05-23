#pragma once

#include <iostream>
#include <vector>

#include "SkillTags.h"

using namespace std;

class ISkill
{
public:
	virtual bool Create();
private:
	std::wstring _skillName;
	std::vector<SkillTags> _skillTags;
};