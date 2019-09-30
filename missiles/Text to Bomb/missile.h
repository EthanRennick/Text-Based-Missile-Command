#pragma once

#include "Coordinates.h"
#include "Target.h"
#include "warhead.h"
#include <iostream>

struct Missile //the missile struct
{
	bool Armed = false;
	Warhead warheadType;
	int warHeadNum;
	Target targetType;
	Coordinates coordinateTarget;
	
	int amountOfWarheads = 5;


	//functions
	void update();
	void arm();
	void selectWarHead();
};
