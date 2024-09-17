#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat bur("Betis", 0);
	std::cout << bur.getName() << std::endl;
	std::cout << bur.getGrade() << std::endl;
	return 0;
}
