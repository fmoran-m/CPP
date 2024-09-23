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
		pepe.signForm(A12);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---SECOND---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 100);
		Form		A12("A12", 100, 100, FALSE);

		std::cout << A12 << std::endl;
		pepe.signForm(A12);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---THIRD---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 99);
		Form		A12("A12", 100, 100, TRUE);

		std::cout << A12 << std::endl;
		pepe.signForm(A12);
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
		pepe.signForm(A12);
		//Exception
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---FIFTH---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 1);
		Form		A12("A12", 151, 100, FALSE);
		//Exception

		std::cout << A12 << std::endl;
		pepe.signForm(A12);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "---SIXTH---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 1);
		Form		A12("A12", 0, 100, FALSE);
		//Exception

		std::cout << A12 << std::endl;
		pepe.signForm(A12);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

std::cout << "---SEVENTH---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 1);
		Form		A12("A12", 100, 151, FALSE);
		//Exception

		std::cout << A12 << std::endl;
		pepe.signForm(A12);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

std::cout << "---EIGHTH---" << std::endl;
	try{
		Bureaucrat	pepe("Pepe", 1);
		Form		A12("A12", 100, 0, FALSE);
		//Exception

		std::cout << A12 << std::endl;
		pepe.signForm(A12);
		std::cout << A12 << std::endl;
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
