#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void){
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

void    Zombie::setName(std::string name)
{
    this->_name = name;
}
