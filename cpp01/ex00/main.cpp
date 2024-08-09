#include "Zombie.hpp"

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

int main(void)
{
	Zombie *newz;

	newz = newZombie("Heap Zombie");
	newz->announce();
	randomChump("Stack Zombie");
	delete(newz);
	return 0;
}
