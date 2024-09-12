#include "Character.hpp"
#include <iostream>

const std::string Character::defaultName = "default";

Character::Character() : name(defaultName){
	for (int i = 0; i < 4; i++){
		inventory[i] = NULL;
	}
	std::cout << "Character default constructor called" << std::endl;
	return;
}

Character::Character(std::string const & name) : name(name){
	for (int i = 0; i < 4; i++){
		inventory[i] = NULL;
	}
	std::cout << "Character name constructor called" << std::endl;
	return;
}

Character::Character(const Character &src) : ICharacter(), name(src.name){
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
	return;
}
	
Character &Character::operator=(const Character &rhs){
	std::cout << "Character assign operator called" << std::endl;
	for (int i = 0; i < 4; i++){
		this->inventory[i] = rhs.inventory[i]->clone();
	}
	return (*this);
}

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
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
	inventory[idx] = 0;
	return;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3){
		std::cout << "Use Error: The inventory index " << idx << " does not exist" << std::endl;
		return;
	}
	if (!inventory[idx]){
		std::cout << "Use Error: The inventory index " << idx << "is empty" << std::endl;
		return;
	}
	std::cout << this->name << " casts " << inventory[idx]->getType() << " on " << target.getName()
		<< std::endl;
}
