#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name) {
	return;
}
HumanA::~HumanA() {
	return ;
}

void	HumanA::setWeapon(Weapon &weapon){
	this->_weapon = weapon;
}

void	HumanA::attack(void){
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
