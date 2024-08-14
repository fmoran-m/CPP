#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name){

	this->_name = name;
	return;
}

Zombie::~Zombie(void){

	std::cout << this->_name << " destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
