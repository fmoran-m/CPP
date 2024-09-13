#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl;
	std::cout << "- SUBJECT MAIN -" << std::endl;
	std::cout << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << tmp << std::endl;
	me->equip(tmp);
	std::cout << tmp << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);


	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	delete tmp;

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
	std::cout << "- SUBJECT MAIN -" << std::endl;
	std::cout << std::endl;

	return 0;
}

