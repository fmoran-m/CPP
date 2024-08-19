#include "Fixed.hpp"
#include <iostream>

int main(void){

	Fixed a(20);
	Fixed b(10);
	Fixed c(30.23f);
	Fixed d(30.23f);
	Fixed e(1);
	Fixed f(10);

	const Fixed j(50);
	const Fixed h(60);

	std::cout << a + b << std::endl; //30
	std::cout << a - b << std::endl; //10
	std::cout << a * b << std::endl; //200
	std::cout << a / b << std::endl; //2
	
	if (a > b)
		std::cout << "> Correcto" << std::endl; 
	if (b < a)
		std::cout << "< Correcto" << std::endl; 
	if ((a > b) && (c == d))
		std::cout << ">= Correcto" << std::endl; 
	if ((b < a) && (c == d))
		std::cout << "<= Correcto" << std::endl; 
	if (a != b)
		std::cout << "!= Correcto" << std::endl; 
	if (c == d)
		std::cout << "== Correcto" << std::endl; 
	
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(j, h) << std::endl;
	std::cout << Fixed::min(j, h) << std::endl;

	std::cout << ++e << std::endl;
	std::cout << e << std::endl;
	std::cout << --e << std::endl;
	std::cout << e << std::endl;
	std::cout << f++ << std::endl;
	std::cout << f << std::endl;
	std::cout << f-- << std::endl;
	std::cout << f << std::endl;

	return 0;
}
