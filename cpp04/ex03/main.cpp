#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main(void){

	AMateria *ice1 = new Ice();

	std::cout << "Ice type: " << ice1->getType() << std::endl;

	std::string pepeName = "Pepe";
	ICharacter *pepe = new Character(pepeName);
	ICharacter *pepeCpy = new Character(*pepe);
	pepe->equip(ice1);
	pepe->use(0, *enemy);
	delete pepe;
	delete enemy;
	return 0; 
}
