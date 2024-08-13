#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	return;
}

Harl::~Harl() {
	return;
}

void	Harl::complain(const std::string &level){

	std::string levelArr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4)
	{
		if (levelArr[i] == level)
			break;
		i++;
	}

	switch(i){

		case 3:
			this->error();
		case 2:
			this->warning();
		case 1:
			this->info();
		case 0:
			this->debug();
			break;
		default:
			std::cout << "Level does not exist" << std::endl;
	}
	return;
}

void	Harl::debug(void){

	std::cout << "[DEBUG]" << std::endl;


	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;

	std::cout << std::endl;
	return;
}

void	Harl::info(void){
	std::cout << "[INFO]" << std::endl;

	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more" << std::endl;

	std::cout << std::endl;
	return;
}

void	Harl::warning(void){

	std::cout << "[WARNING]" << std::endl;

	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;

	std::cout << std::endl;
	return;
}

void	Harl::error(void){

	std::cout << "[ERROR]" << std::endl;

	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;

	std::cout << std::endl;
	return;
}
