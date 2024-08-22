#include "ClapTrap.hpp"
#include <iostream>
#include <climits>

//Canonic form and constructors

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(10){
	std::cout << "ClapTrap default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap name constructor " << name << " called" << std::endl;
	return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cpy){
	//std::cout << "ClapTrap assign operator called" << std::endl;
	this->_hitPoints = cpy._hitPoints;
	this->_energyPoints = cpy._energyPoints;
	this->_attackDamage = cpy._attackDamage;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &src) : _name(src._name){
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap(void){
	return;
}

//Getters

unsigned int	ClapTrap::getHitPoints(void){
	return this->_hitPoints;
}
unsigned int	ClapTrap::getEnergyPoints(void){
	return this->_energyPoints;
}
unsigned int	ClapTrap::getAttackDamage(void){
	return this->_attackDamage;
}

//Actions member functions

void	ClapTrap::attack(const std::string &target){

	if (_energyPoints < 1)
	{
		std::cout << "Not enough energy points" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", "
	<< "causing " << this->_attackDamage << " points of damage!" << std::endl;

	this->_energyPoints--;

	return;
}

void	ClapTrap::beRepaired(unsigned int amount){

	long long int longAmount = amount;
	if (_energyPoints < 1)
	{
		std::cout << "Not enough energy points" << std::endl;
		return;
	}
	if (longAmount > UINT_MAX || (longAmount + this->_hitPoints) > UINT_MAX)
		amount = UINT_MAX - this->_hitPoints; // In this case, we change the amount because ClapTrap can not have more points than the unsigned int

	this->_hitPoints += amount;
	this->_energyPoints--;

	std::cout << "ClapTrap " << this->_name << " heals " << amount << " hit points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " receives " << amount << " points of damage!" << std::endl;

	if (amount >= this->_hitPoints)
	{
		std::cout << "Claptrap is dead." << std::endl;
		this->_hitPoints = 0;
		return ;
	}

	this->_hitPoints -= amount;

	return;
}
