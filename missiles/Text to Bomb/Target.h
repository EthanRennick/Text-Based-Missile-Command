#pragma once

struct Target
{
	int x;
	int y;
	int factoryHealth = 1;
	int hqHealth = 2;

	bool targetDestroyed;

	void print()
	{
		std::cout << x << " , " << y;
	};

	void printHealth()
	{
		std::cout << "Hq coords -> (4,2)\nHq health: " << hqHealth << std::endl;
		std::cout << "Factory coords -> (6,9)\nFactory Health: " << factoryHealth << std::endl;
	}
};