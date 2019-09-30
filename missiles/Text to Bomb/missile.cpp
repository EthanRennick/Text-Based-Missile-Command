#include "missile.h"

void Missile::update()
{
	

}

void Missile::arm()
{
	int armPicker = 0;
	std::cout << "Arm missile? Press any key to arm. \n ";
	std::cin >> armPicker; 

	if (Armed)
		Armed = false;
	else
		Armed = true;
}

void Missile::selectWarHead()
{
}
