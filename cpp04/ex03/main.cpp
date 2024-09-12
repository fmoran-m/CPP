#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main(void){

	AMateria *ice1 = new Ice();
	AMateria *ice2 = new Ice();
	AMateria *cure1 = new Cure();
	AMateria *cure2 = new Cure();

	ICharacter *pepe = new Character("pepe");
	ICharacter *betis = new Character("betis");
	pepe->equip(ice1);
	pepe->equip(ice2);
	pepe->equip(cure1);
	pepe->equip(cure2);
	pepe->use(0, *betis);
	pepe->use(1, *betis);
	pepe->use(2, *betis);
	pepe->use(3, *betis);
	*betis = *pepe;
	delete(betis);
	delete(pepe);
	return 0; 
}
