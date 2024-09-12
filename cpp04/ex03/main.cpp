#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main(void){

	AMateria *ice1 = new Ice();

//	std::cout << "Ice type: " << ice.getType() << std::endl;
//	std::cout << "Cure type: " << cure.getType() << std::endl;

	ICharacter *character = new Character("Pepe");
	character->equip(ice1);
	character->use(0, *character);
	delete character;
	delete ice1;
	return 0; 
}
