#pragma once

#include <time.h>

#include "ISkill.h"
#include "SkillTags.h"

class BlisteringBolt : ISkill
{
public:
	
	double GetDamage(double timeStamp)
	{
		double adjusted = _attackPerSecond * 1000;
		if((_lastAttackTimeMS + adjusted) <= timeStamp)
		{
			_lastAttackTimeMS = timeStamp;
			int dmg = rand() % 2755 + 1837;
			return dmg;
		}
		return 0;
	}

	BlisteringBolt(void)
	{
		 srand (time(NULL));
		 _skillName = L"Blistering Bolt";
		_minDamage = 1837;
		_maxDamage = 2755;
		_attackPerSecond = 3.0;
	}

	~BlisteringBolt(void);

private:
	

	double _minDamage;
	double _maxDamage;
	double _attackPerSecond;
	double _lastAttackTimeMS;
};

