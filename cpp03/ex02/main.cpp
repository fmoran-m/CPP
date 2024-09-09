#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	/* CLAPTRAP */
	//Base Class

	ClapTrap	android("Clap");
	ClapTrap	cpy(android);

	std::cout << "Clap Energy Points: " << android.getEnergyPoints() << std::endl;
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;
	std::cout << "Clap Attack Points: " << android.getAttackDamage() << std::endl;

	android.attack("monster");
	std::cout << "Clap Energy Points: " << android.getEnergyPoints() << std::endl;
	
	android.beRepaired(5);
	std::cout << "Clap Energy Points: " << android.getEnergyPoints() << std::endl;
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;
	android.takeDamage(10);
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;
	android.takeDamage(10);
	std::cout << "Clap Hit Points: " << android.getHitPoints() << std::endl;
	android.beRepaired(5);

	//Inherited Class

	ScavTrap scav("scav");
	ScavTrap scavCpy("ScavCpy");

	std::cout << "Scav Energy Points: " << scav.getEnergyPoints() << std::endl;
	std::cout << "Scav Hit Points: " << scav.getHitPoints() << std::endl;
	std::cout << "Scav Attack Points: " << scav.getAttackDamage() << std::endl;
	scav.attack("monster");
	std::cout << "Scav Energy Points: " << scav.getEnergyPoints() << std::endl;

	scav.guardGate();

	//Inherited class with base prints

	scav.beRepaired(5);
	std::cout << "Scav Hit Points: " << scav.getHitPoints() << std::endl;
	std::cout << "Scav Energy Points: " << scav.getEnergyPoints() << std::endl;
	scav.takeDamage(10);
	std::cout << "Scav Hit Points: " << scav.getHitPoints() << std::endl;
	scav.takeDamage(100);
	std::cout << "Scav Hit Points: " << scav.getHitPoints() << std::endl;
	scav.beRepaired(5);
	scav.attack("monster");

	/* FragTrap */
	//Inherited Class
	
	FragTrap frag("frag");
	FragTrap fragCpy(frag);

	std::cout << "frag Energy Points: " << frag.getEnergyPoints() << std::endl;
	std::cout << "frag Hit Points: " << frag.getHitPoints() << std::endl;
	std::cout << "frag Attack Points: " << frag.getAttackDamage() << std::endl;
	frag.attack("monster");
	std::cout << "frag Energy Points: " << frag.getEnergyPoints() << std::endl;

	frag.highFivesGuys();

	//Inherited class with base prints

	frag.beRepaired(20);
	std::cout << "frag Hit Points: " << frag.getHitPoints() << std::endl;
	std::cout << "frag Energy Points: " << frag.getEnergyPoints() << std::endl;
	frag.takeDamage(7);
	std::cout << "frag Hit Points: " << frag.getHitPoints() << std::endl;
	frag.takeDamage(120);
	std::cout << "frag Hit Points: " << frag.getHitPoints() << std::endl;
	frag.beRepaired(5);
    frag.attack("monster");

	return 0;
}
