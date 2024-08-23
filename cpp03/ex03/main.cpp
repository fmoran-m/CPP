#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	/* CLAPTRAP */

	//Base Class
	/*
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
*/
	/* SCAVTRAP */
	//Inherited Class
/*
	ScavTrap scav("scav");
	ScavTrap scavCpy(scav);

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
*/
	/* FlagTrap */
	//Inherited Class
/*	
	FragTrap frag("frag");
	FragTrap fragCpy(fragCpy);

	std::cout << "frag Energy Points: " << frag.getEnergyPoints() << std::endl;
	std::cout << "frag Hit Points: " << frag.getHitPoints() << std::endl;
	std::cout << "frag Attack Points: " << frag.getAttackDamage() << std::endl;
	frag.attack("monster");

	frag.highFivesGuys();

	//Inherited class with base prints

	frag.beRepaired(20);
	std::cout << "flag Hit Points: " << frag.getHitPoints() << std::endl;
	frag.takeDamage(7);
	std::cout << "flag Hit Points: " << frag.getHitPoints() << std::endl;
	frag.takeDamage(12);
	std::cout << "flag Hit Points: " << frag.getHitPoints() << std::endl;
*/

	DiamondTrap diamond("diamond");
	DiamondTrap	diamondCpy("diamondCpy");

	std::cout << "diamond Energy Points: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "diamond Hit Points: " << diamond.getHitPoints() << std::endl;
	std::cout << "diamond Attack Points: " << diamond.getAttackDamage() << std::endl;

	diamond.attack("monster");
	diamond.whoAmI();

	diamond.beRepaired(20);
	std::cout << "flag Hit Points: " << diamond.getHitPoints() << std::endl;
	diamond.takeDamage(7);
	std::cout << "flag Hit Points: " << diamond.getHitPoints() << std::endl;
	diamond.takeDamage(12);
	std::cout << "flag Hit Points: " << diamond.getHitPoints() << std::endl;

	return 0;
}
