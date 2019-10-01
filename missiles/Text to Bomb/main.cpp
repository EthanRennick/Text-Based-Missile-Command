/// <summary>
/// Here's a little game i made
/// you might want to read it
/// code for code
/// but dont worry
/// shoot missiles
/// ---
/// Author:
/// Ethan Rennick
/// C00240102
/// started 24.9.19
/// ---
/// Description:
/// A text based missile command esque game 
/// ---
/// For:
/// A Phil project in Games Programming 
/// Year 2
/// ---
/// Known bugs?
/// </summary>

#include <iostream>
#include "missile.h"
#include <string>

Missile weapon;

bool coordIncrease();


int play()
{
	std::string launchCode = "";
	int warHeadNum = 0;
	bool targetReached = false;

	std::cout << "You have " << weapon.amountOfWarheads << " remaing. \n";
	std::cout << "Choose a missile type. We have 1/Explosive, 2/Nuclear, 3/Smol \n";
	std::cin >> warHeadNum;

	if (warHeadNum == 1)
	{
		weapon.warheadType.EXPLOSIVE; 
		weapon.warheadType.explos = true;
		 weapon.warheadType.nuclear = false;
		 weapon.warheadType.smol = false;


	}
	else if (warHeadNum == 2)
	{
		weapon.warheadType.NUCLEAR;
		weapon.warheadType.explos = false;
		weapon.warheadType.nuclear = true;
		weapon.warheadType.smol = false;


	}
	else if (warHeadNum == 3)
	{
		weapon.warheadType.SMOL;
		weapon.warheadType.explos = false;
		weapon.warheadType.nuclear = false;
		weapon.warheadType.smol = true;


	}
	weapon.targetType.printHealth();

	std::cout << "Please enter a target for the missile. The target is hiding at the Answer to the Ultimate Question of Life,\n the Universe, and Everything TM. \n";
	std::cout << "Enter the x coordinate:  ";
	std::cin >> weapon.targetType.x;
	std::cout << std::endl << "Now Enter the y coordinate: ";
	std::cin >> weapon.targetType.y;
	std::cout << std::endl;
	std::cout << "Coordinates entered as:  ";
	weapon.targetType.print();
	std::cout << std::endl;

	std::cout << "Please Enter the launch code, commandant. (Hint - the best lecturer around's name) \n";
	std::cin >> launchCode;

	if (launchCode == "phil")
	{
		std::cout << "Launch code accepted. \n";
		weapon.arm();
	}
	else

	{
		std::cout << "Error with Launch Code. \nPossible sabotage detected. \nTerminating interface. \n";
		return 0;
	}

	std::cout << "Firing phase initialised.\nWarhead selected? Check \nTarget acquired? Check\nLaunch code accepted? Check\n";
	std::cout << "Firing missile. \n";
	std::cout << "Woooosh *missile noises* \n";

	weapon.coordinateTarget.x = weapon.targetType.x;
	weapon.coordinateTarget.y = weapon.targetType.y;
	
	while (targetReached == false)
	{
		targetReached = coordIncrease();
	}

	std::cout << "Missile Collission! \n";
	std::cout << "The missile hit your coordinates. \n";

	if (weapon.coordinateTarget.x == 4 && weapon.coordinateTarget.y == 2 && weapon.warheadType.explos==true)
	{
		std::cout << "You hit the enemy HQ with the explosive warhead! \n";
		weapon.targetType.hqHealth -=  1;
		weapon.targetType.printHealth();
	}
	else if (weapon.coordinateTarget.x == 4 && weapon.coordinateTarget.y == 2 && weapon.warheadType.smol ==true)
	{
		std::cout << "You hit the enemy HQ with the SMOL goth gf warhead uwu *nuzzles you* *pounces on enemy* \n";
		weapon.targetType.printHealth();
		std::cout << "Target is unaffected by her OWOs. ( those fiendish e-boys :c ) \n";
	}
	else if (weapon.coordinateTarget.x == 4 && weapon.coordinateTarget.y == 2 && weapon.warheadType.nuclear==true)
	{
		std::cout << "You hit the enemy HQ with the nuclear warhead! \n";
		weapon.targetType.hqHealth -= 2;
		weapon.targetType.printHealth();
		std::cout << "Target obliterated.";
	}
	else if (weapon.coordinateTarget.x == 6 && weapon.coordinateTarget.y == 9 && weapon.warheadType.explos==true)
	{
		std::cout << "You hit the enemy factory with the explosive warhead! \n";
		weapon.targetType.factoryHealth -= 1;
		weapon.targetType.printHealth();
		std::cout << "Got 'em, coach.\n";
	}
	else if (weapon.coordinateTarget.x == 6 && weapon.coordinateTarget.y == 9 && weapon.warheadType.nuclear==true)
	{
		std::cout << "You hit the enemy factory with the nuclear warhead! \n";
		weapon.targetType.factoryHealth -= 2;
		weapon.targetType.printHealth();
		std::cout << "Blamo! \n";
	}
	else if (weapon.coordinateTarget.x == 6 && weapon.coordinateTarget.y == 9 && weapon.warheadType.smol==true)
	{
		std::cout << "You hit the enemy factory with the smol waifu warhead! \n";
		std::cout << "The workers are distracted! \n";
		weapon.targetType.factoryHealth = 0;
		weapon.targetType.printHealth();
	}
	else if ((weapon.coordinateTarget.x != 6 && weapon.coordinateTarget.y != 9) || (weapon.coordinateTarget.x != 4 && weapon.coordinateTarget.y != 2))
	{
		std::cout << "Commandant - no points. :( \n";
		std::cout << "Our missile failed to hit a target \n";
		weapon.targetType.printHealth();
	}
	weapon.warheadType.explos == false;
	weapon.warheadType.nuclear == false;
	weapon.warheadType.smol == false;

	weapon.amountOfWarheads -= 1;
	std::cout << "You have " << weapon.amountOfWarheads << " remaing. \n";

	if (weapon.targetType.factoryHealth <= 0 && weapon.targetType.hqHealth <= 0)
	{
		std::cout << "All targets destroyed. Well done commandant.\nTerminating Interface.\n";
		return 0;
	}

	if (weapon.amountOfWarheads == 0)
	{
		std::cout << "All out of warheads. Terminating interface. \n";
		return 0;
	}

	int proceed = 0;
	std::cout << "Would you like to continue the bombardment?   1/y   2/n \n";
	std::cin >> proceed;

	if (proceed == 2)
	{
		std::cout << "Terminating Interface. \n";
		return 0;
	}
	else
	{
		std::cout << "Continuing bombardment... \n";
		return 1;
	}


};


/// <summary>
/// introduction to missile game
/// </summary>
/// <returns></returns>
int main()
{
	int playGam = 0;
	std::cout << "Are you ready commandant? ( 1/yes - 2/no ) \n";
	std::cin >> playGam;
	if (playGam == 1)
	{
		//play the main game function
		while(play() == 1)
		{
			play();
		}
	}
	else
	{
		std::cout << "Then the enemy shall prevail. \n";
	}

	
	system("pause");
	return 0;
}


bool coordIncrease() 
{
	if (weapon.targetType.x > 0)
	{
		weapon.targetType.x -= 1;
	}
	if (weapon.targetType.y > 0)
	{
		weapon.targetType.y -= 1;
	}

	if (weapon.targetType.x == 0 && weapon.targetType.y == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

};