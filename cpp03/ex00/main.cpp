#include "ClapTrap.hpp"
#include <iostream>

int main(void){

	ClapTrap	android("ANDROID");
	ClapTrap	cpy(android);

	std::cout << "Energy Points: " << android.getEnergyPoints() << std::endl;
	std::cout << "Hit Points: " << android.getHitPoints() << std::endl;
	std::cout << "Attack Points: " << android.getAttackDamage() << std::endl;

	android.attack("monster");
	std::cout << "Energy Points: " << android.getEnergyPoints() << std::endl;

	android.beRepaired(5);
	std::cout << "Hit Points: " << android.getHitPoints() << std::endl;

	android.takeDamage(10);
	std::cout << "Hit Points: " << android.getHitPoints() << std::endl;

	android.takeDamage(10);
	std::cout << "Hit Points: " << android.getHitPoints() << std::endl;
	
	android.beRepaired(50);
	std::cout << "Hit Points: " << android.getHitPoints() << std::endl;

	android.beRepaired(24);
	std::cout << "Hit Points: " << android.getHitPoints() << std::endl;

	return 0;
}
