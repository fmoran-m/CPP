#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
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
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	}
	{
	std::cout << std::endl;
	std::cout << "- SUBJECT MAIN -" << std::endl;
	std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << "---------------------" << std::endl;
	src->learnMateria(new Cure());
	std::cout << "---------------------" << std::endl;

	ICharacter* bob = new Character("bob");
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	AMateria* tmp2;
	tmp2 = src->createMateria("cure");

	std::cout << "---------------------" << std::endl;
	me->equip(tmp2);
	std::cout << "---------------------" << std::endl;

	delete tmp2;

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << "---------------------" << std::endl;
	me->use(-1, *bob);
	me->use(4, *bob);
	me->unequip(-1);
	me->unequip(4);
	std::cout << "---------------------" << std::endl;

	delete(src);
	delete(me);
	delete(bob);
	}
	MateriaSource src;
	MateriaSource srcCpy;
	Character me("me");
	Character meCpy("meCpy");
	Character bob("bob");

	src.learnMateria(new Ice());
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());
	src.learnMateria(new Cure());

	srcCpy = src;

	AMateria* tmp;
	tmp = srcCpy.createMateria("ice");
	me.equip(tmp);
	tmp = srcCpy.createMateria("ice");
	me.equip(tmp);
	tmp = srcCpy.createMateria("cure");
	me.equip(tmp);
	tmp = srcCpy.createMateria("cure");
	me.equip(tmp);
	meCpy = me;

	meCpy.use(0, bob);
	meCpy.use(1, bob);
	meCpy.use(2, bob);
	meCpy.use(3, bob);

	return 0;
}

