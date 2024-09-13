#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	{
		//Subject Tests
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
		//Full Inventory Tests
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice("ice"));
	src->learnMateria(new Ice("fire"));
	src->learnMateria(new Cure("cure"));
	src->learnMateria(new Cure("wind"));

	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	src->learnMateria(new Cure()); //New Cure deleted inside the function
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("wind");
	me->equip(tmp);
	AMateria* tmp2;
	tmp2 = src->createMateria("cure");

	std::cout << "---------------------" << std::endl;
	me->equip(tmp2); //Tmp2 not deleted inside the function
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	delete tmp2; //Deleting tmp2

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << std::endl;
		//Error access to arrays
	std::cout << "---------------------" << std::endl;
	me->use(-1, *bob);
	me->use(4, *bob);
	me->unequip(-1);
	me->unequip(4);
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	//Unequip test
	me->unequip(3);

	std::cout << "---------------------" << std::endl;
	me->use(3, *bob);
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	delete(tmp);

	delete(src);
	delete(me);
	delete(bob);
	}
	{
	//Copy tests
	MateriaSource src;
	MateriaSource srcCpy;
	Character me("me");
	Character meCpy("meCpy");
	Character bob("bob");

	src.learnMateria(new Ice());
	src.learnMateria(new Ice("fire"));
	src.learnMateria(new Cure());
	src.learnMateria(new Cure("wind"));

	srcCpy = src;

	AMateria* tmp;
	tmp = srcCpy.createMateria("ice");
	std::cout << tmp->getType() << std::endl;
	me.equip(tmp);
	tmp = srcCpy.createMateria("fire");
	std::cout << tmp->getType() << std::endl;
	me.equip(tmp);
	tmp = srcCpy.createMateria("wind");
	std::cout << tmp->getType() << std::endl;
	me.equip(tmp);
	tmp = srcCpy.createMateria("cure");
	std::cout << tmp->getType() << std::endl;
	me.equip(tmp);

	meCpy = me;

	std::cout << std::endl;

	meCpy.use(0, bob);
	meCpy.use(1, bob);
	meCpy.use(2, bob);
	meCpy.use(3, bob);
	}
	{
/*
	ICharacter *me = new Character("me");
	ICharacter *meCpy = new Character("meCpy");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice("ice"));
	src->learnMateria(new Ice("fire"));
	src->learnMateria(new Cure("cure"));
	src->learnMateria(new Cure("wind"));

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("wind");
	me->equip(tmp);

	*meCpy = *me;
	meCpy->use(0, *me);
	meCpy->use(1, *me);
	meCpy->use(2, *me);
	meCpy->use(3, *me);
	delete(me);
	delete(meCpy);
	delete(src);
*/
	return 0;
}

}
