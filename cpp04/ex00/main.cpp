#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main(void){

	Animal *animal = new Animal(); //Class Animal
	Animal *cat = new Cat(); //An animal that, in this case, is a cat, but it could be something else
	Animal *dog = new Dog(); //Same with a Dog
	WrongAnimal *wrongcat = new WrongCat(); // Non virtual cat

	Animal cpyAnimal(*animal); //Copy of class animal
	Animal cpyDog(*dog); //Copy of this animal, in this case a dog
	Animal cpyCat(*cat); //Copy of this animal, in this case a cat
	WrongAnimal cpyWrongCat(*wrongcat); //Copy non virtual cat
	
	std::cout << "animal type: " << animal->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;
	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "wrongcat type: " << wrongcat->getType() << std::endl;

	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
	wrongcat->makeSound();

	delete cat;
	delete dog;
	delete animal;
	delete wrongcat;

	return 0;
}
