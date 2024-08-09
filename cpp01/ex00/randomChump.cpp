#include "Zombie.hpp"

void		randomChump(std::string name)
{
	Zombie	ran(name);

	ran.announce();

	return;
}
