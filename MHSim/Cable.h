#pragma once
#include "IHero.h"

class Cable : IHero
{
public:
	Cable(void);
	~Cable(void);
	bool Create();
	void DoSimulate(double timeStamp);



};

