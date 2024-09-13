#include "Character.hpp"
#include <iostream>

Character::Character() : name("default"){
	for (int i = 0; i < 4; i++){
		inventory[i] = NULL;
	}
	this->unequipPtr = NULL;
	//std::cout << "Character default constructor called" << std::endl;
	return;
}

Character::Character(std::string name) : name(name){
	for (int i = 0; i < 4; i++){
		inventory[i] = NULL;
	}
	//std::cout << "Character name constructor called" << std::endl;
	return;
}

Character::Character(const Character &src){
	//std::cout << "Character copy constructor called" << std::endl;
	*this = src;
	return;
}
	
Character &Character::operator=(const Character &rhs){
//	std::cout << "Character assign operator called" << std::endl;
	name = rhs.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (rhs.inventory[i])
			this->inventory[i] = rhs.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	//std::cout << "Character destructor called" << std::endl;
	return;
}

std::string const &Character::getName() const{
	return(this->name);
}

void	Character::equip(AMateria *m){
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
	std::cout << "Equip Error: Inventory is full" << std::endl;
	return;
}

void	Character::unequip(int idx){
	if (idx < 0 || idx > 3){
		std::cout << "Unequip Error: The inventory index " << idx << " does not exist" << std::endl;
		return;
	}
	unequipPtr = inventory[idx];
	inventory[idx] = NULL;
	return;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3){
		std::cout << "Use Error: The inventory index " << idx << " does not exist" << std::endl;
		return;
	}
	if (!inventory[idx]){
		std::cout << "Use Error: The inventory index " << idx << " is empty" << std::endl;
		return;
	}
	inventory[idx]->use(target.getName());
}
