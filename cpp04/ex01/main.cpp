#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void){

	std::cout << std::endl;
	std::cout << "------------------ARRAY OF ANIMALS------------------" << std::endl;
	std::cout << std::endl;

	Animal *array[10];

	for(int i = 0; i < 5; i++)
	{
		std::cout << "Array index: " << i << std::endl;
		array[i] = new Dog();
	}

	for(int i = 5; i < 10; i++)
	{
		std::cout << "Array index: " << i << std::endl;
		array[i] = new Cat();
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Array index: " << i << std::endl;
		delete array[i];
	}

	std::cout << std::endl;
	std::cout << "------------------IDEAS EXTRACTION------------------" << std::endl;
	std::cout << std::endl;

	Animal *cat = new Cat();
	Animal *dog = new Dog();
	cat->getBrain()->setIdea(0, "zero cat idea");
	dog->getBrain()->setIdea(0, "zero dog idea");
	cat->getBrain()->setIdea(5, "fifth cat idea");
	dog->getBrain()->setIdea(5, "fifth dog idea");
	std::cout << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << dog->getBrain()->getIdea(0) << std::endl;
	delete dog;
	delete cat;

	std::cout << std::endl;
	std::cout << "------------------DEEP COPY------------------" << std::endl;
	std::cout << std::endl;

	Cat catStack;
	Cat catCpyStack(catStack);

	catStack.getBrain()->setIdea(0, "Regular cat first idea");
	catCpyStack.getBrain()->setIdea(0, "Cpy cat first idea");

	std::cout << catStack.getBrain() << std::endl;
	std::cout << catCpyStack.getBrain() << std::endl;

	std::cout << catStack.getBrain()->getIdea(0) << std::endl;
	std::cout << catCpyStack.getBrain()->getIdea(0) << std::endl;

	return 0;
}
