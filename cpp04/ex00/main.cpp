#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void){

	Animal *cat = new Cat(); //An animal that, in this case, is a cat, but it could be something else
	Animal *dog = new Dog(); //Same with a Dog

	Animal cpyDog(*dog); //Copy of this animal, in this case a dog
	Animal cpyCat(*cat); //Copy of this animal, in this case a cat

	cat->makeSound();
	dog->makeSound();
	return 0;
}
