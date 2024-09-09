#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"){

	this->_name = "Default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints; 
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap default constructor called" << std::endl;

	return;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"){

	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints; 
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap name constructor " << name << " called" << std::endl;

	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src._name + "_clap_name"), ScavTrap(src), FragTrap(src){

	std::cout << "DiamondTrap copy constructor called" << std::endl;

	*this = src;
	return;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy){

	std::cout << "DiamondTrap assign operator called" << std::endl;

	this->_name = cpy._name;
	this->_hitPoints = cpy._hitPoints;
	this->_energyPoints = cpy._energyPoints;
	this->_attackDamage = cpy._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "DiamondTrap destructor called" << std::endl;
	return;
}

void DiamondTrap::attack(std::string const &target){

	ScavTrap::attack(target);
	return;
}
void DiamondTrap::whoAmI(){
	std::cout << "Am I a DiamondTrap named " << this->_name << ", a Claptrap named " << ClapTrap::_name << ", an horrendous mix of different androids, or just dust accross the galaxy?" << std::endl;
}
