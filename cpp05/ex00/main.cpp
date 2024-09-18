#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "------------------- VALID GRADES -------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bur("Captain", 1);
		std::cout << bur << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur("Soldier", 150);
		std::cout << bur << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur("Liutenant", 63);
		std::cout << bur << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------- ERROR GRADES -----------------" << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bur("God", 0);
		std::cout << bur << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur("Peasant", 151);
		std::cout << bur << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur("Zombie", -12);
		std::cout << bur << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur("Trascendence", 312);
		std::cout << bur << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur("Captain", 1);
		bur.promotion();
		std::cout << bur << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bur("Soldier", 150);
		bur.relegation();
		std::cout << bur << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
