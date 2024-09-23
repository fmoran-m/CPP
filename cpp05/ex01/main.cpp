#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << "---FIRST---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 99);
		Form		A12("A12", 100, 100, FALSE);

		std::cout << A12 << std::endl;
		A12.beSigned(pepe);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---SECOND---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 100);
		Form		A12("A12", 100, 100, FALSE);

		std::cout << A12 << std::endl;
		A12.beSigned(pepe);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---THIRD---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 99);
		Form		A12("A12", 100, 100, TRUE);

		std::cout << A12 << std::endl;
		A12.beSigned(pepe);
		//Print error, but not exception
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---FOURTH---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 101);
		Form		A12("A12", 100, 100, FALSE);

		std::cout << A12 << std::endl;
		A12.beSigned(pepe);
		//Exception
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---FIFTH---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 151);
		Form		A12("A12", 100, 100, FALSE);
		//Exception

		std::cout << A12 << std::endl;
		A12.beSigned(pepe);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---SIXTH---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 0);
		Form		A12("A12", 100, 100, FALSE);
		//Exception

		std::cout << A12 << std::endl;
		A12.beSigned(pepe);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

return 0;
}
