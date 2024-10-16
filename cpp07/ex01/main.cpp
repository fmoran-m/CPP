#include <iostream>
#include <string>
#include "iter.hpp"

int main(void){
	int a[20] = {1, 2, 3, 4, 5, 6, 7};
	iter(a, 7, plusOne);
	for (int i = 0; i < 7; i++){
		std::cout << a[i] << std::endl;
	}
	char b[20] = "abcdefg";
	iter(b, 7, plusOne); 
	for (int i = 0; i < 7; i++){
		std::cout << b[i] << std::endl;
	}
	return 0;
}
//No estoy pasando el length del array, estoy pasando el numero de caracteres a los que voy pasar la funcion