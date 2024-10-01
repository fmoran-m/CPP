#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){
	return;
}
HumanB::~HumanB() {
	return ;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}

void	HumanB::attack(void){
	if (this->_weapon == NULL)
	{
		std::cout << this->_name << " needs a weapon!" << std::endl;
		return;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return;
}
