#include <iostream>
#include <string>
#include "iter.hpp"

int main(void){
	std::cout << "INT ARRAY - Start" << std::endl;

	int a[7] = {1, 2, 3, 4, 5, 6, 7};
	iter(a, 7, plusOne);
	for (int i = 0; i < 7; i++){
		std::cout << a[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "CHAR ARRAY - Start" << std::endl;

	char b[8] = "abcdefg";

	//std::cout <<"Null casted: "<< static_cast<int>(b[7]) << std::endl;

	iter(b, 7, plusOne); 
	for (unsigned int i = 0; i < sizeof(b) - 1; i++){
		std::cout << b[i] << std::endl;
	}

	//std::cout <<"Null casted: "<< static_cast<int>(b[7]) << std::endl;

return 0;
}