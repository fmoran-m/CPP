#include "Zombie.hpp"

Zombie	*zombieHorde(std::string name, int N)
{
	Zombie *horde = new Zombie[N];
    for(int i = 0; i < N; i++)
        horde[i].setName(name);
	return horde;
}
