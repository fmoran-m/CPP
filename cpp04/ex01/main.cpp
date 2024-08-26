#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void){

	Animal *array[10];

	for(int i = 0; i < 5; i++)
		array[i] = new Dog;

	for(int i = 5; i < 10; i++)
		array[i] = new Cat;

	for (int i = 0; i < 10; i++)
		delete array[i];

	return 0;
}
