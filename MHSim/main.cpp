#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

#include "ISkill.h"
#include "BlisteringBolt.h"

using namespace std;

int main(int argc, char** argv)
{

	BlisteringBolt* s = new BlisteringBolt();
	while(true)
	{
		auto now = std::chrono::steady_clock::now().time_since_epoch();
		double ts = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
		double dmg = s->GetDamage(ts);
		if( dmg > 0)
		{
			std::cout << "Cable's [Blistering Bolt] did " << dmg << " Damage" << endl;
		}
	}
	return 0;
}