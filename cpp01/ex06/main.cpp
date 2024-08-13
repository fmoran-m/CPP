#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv){

	std::string level;

	if (argc != 2)
	{
		std::cout << "Error: incorrect number of arguments" << std::endl;
		return 1;
	}

	level = (std::string)argv[1];
	Harl	harl;
	harl.complain(level);

	return 0;
}
