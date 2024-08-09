#include "Zombie.hpp"

Zombie*		newZombie(std::string name)
{
	Zombie *newz = new Zombie(name);
	return (newz);
}
