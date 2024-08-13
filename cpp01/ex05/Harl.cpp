#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	return;
}

Harl::~Harl() {
	return;
}

void	Harl::complain(std::string level){

	void (Harl::*funcPtr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levelArr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (levelArr[i] == level)
		{
			(this->*funcPtr[i])();
			return;
		}
	}
	return;
}

void	Harl::debug(void){
	std::cout << std::endl;

	std::cout << "DEBUG" << std::endl;

	std::cout << std::endl;

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return;
}

void	Harl::info(void){
	std::cout << std::endl;

	std::cout << "INFO" << std::endl;

	std::cout << std::endl;

	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more" << std::endl;
	return;
}

void	Harl::warning(void){
	std::cout << std::endl;

	std::cout << "WARNING" << std::endl;

	std::cout << std::endl;

	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return;
}

void	Harl::error(void){
	std::cout << std::endl;

	std::cout << "ERROR" << std::endl;

	std::cout << std::endl;

	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return;
}
