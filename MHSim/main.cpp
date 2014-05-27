#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

#include "IHero.h"
#include "Cable.h"

using namespace std;

int main(int argc, char** argv)
{
	Cable* c = new Cable();
	c->Create();
	srand (time(NULL));
	while(true)
	{
		auto now = std::chrono::steady_clock::now().time_since_epoch();
		double ts = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
		c->DoSimulate(ts);
	}
	return 0;
}