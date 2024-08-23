#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap("Default"){

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap default constructor called" << std::endl;

	return;
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name){

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap name constructor " << name << " called" << std::endl;

	return;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src._name){

	std::cout << "FragTrap copy constructor called" << std::endl;

	*this = src;
	return;
}
FragTrap &FragTrap::operator=(const FragTrap &cpy){

	//std::cout << "FragTrap assign operator called" << std::endl;

	this->_hitPoints = cpy._hitPoints;
	this->_energyPoints = cpy._energyPoints;
	this->_attackDamage = cpy._attackDamage;
	return (*this);
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap destructor called" << std::endl;
	return;
}

void FragTrap::attack(std::string const &target){

	if (_energyPoints < 1)
	{
		std::cout << "FragTrap " << this->_name << ": Not enough energy points" << std::endl;
		return;
	}

	std::cout << "FragTrap " << this->_name << " obliterates " << target << ", "
	<< "causing " << this->_attackDamage << " points of damage!" << std::endl;

	this->_energyPoints--;

	return;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap " << this->_name << " HIGH FIVES GUYS!" << std::endl;
}
