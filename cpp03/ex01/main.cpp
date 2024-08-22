#include "ScavTrap.hpp"
#include <iostream>
#include <climits>

int main(void)
{
	//Base Class
	
	ClapTrap	android("Clap");
	ClapTrap	cpy(android);

	std::cout << "Clap Energy Points: " <<android.getEnergyPoints() << std::endl;
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;
	std::cout << "Clap Attack Points: " << android.getAttackDamage() << std::endl;

	std::cout << "Clap Energy Points: " << android.getEnergyPoints() << std::endl;
	android.attack("monster");
	std::cout << "Clap Energy Points: " << android.getEnergyPoints() << std::endl;
	
	android.beRepaired(5);
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;
	android.takeDamage(10);
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;
	android.takeDamage(10);
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;

	android.beRepaired(50);
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;
	android.beRepaired(24);
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;

	//Inherited Class

	ScavTrap scav("scav");
	ScavTrap scavCpy("ScavCpy");

	std::cout << "Scav Energy Points: " << scav.getEnergyPoints() << std::endl;
	std::cout << "Scav Hit Points: " << scav.getHitPoints() << std::endl;
	std::cout << "Scav Attack Points: " << scav.getAttackDamage() << std::endl;
	scav.attack("monster");

	scav.guardGate();

	//Inherited class with base prints

	scav.beRepaired(5);
	std::cout << "Scav Hit Points: " << scav.getHitPoints() << std::endl;
	scav.takeDamage(10);
	std::cout << "Scav Hit Points: " << scav.getHitPoints() << std::endl;
	scav.takeDamage(10);
	std::cout << "Scav Hit Points: " << scav.getHitPoints() << std::endl;


	return 0;
}
