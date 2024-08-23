#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap("Default"){

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap default constructor called" << std::endl;

	return;
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap name constructor " << name << " called" << std::endl;

	return;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src._name){

	std::cout << "ScavTrap copy constructor called" << std::endl;

	*this = src;
	return;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &cpy){

	//std::cout << "ScavTrap assign operator called" << std::endl;

	this->_hitPoints = cpy._hitPoints;
	this->_energyPoints = cpy._energyPoints;
	this->_attackDamage = cpy._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap destructor called" << std::endl;
	return;
}

void ScavTrap::attack(std::string const &target){

	if (_energyPoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << ": Not enough energy points" << std::endl;
		return;
	}

	std::cout << "ScavTrap " << this->_name << " slashes " << target << ", "
	<< "causing " << this->_attackDamage << " points of damage!" << std::endl;

	this->_energyPoints--;

	return;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode" << std::endl;
}
