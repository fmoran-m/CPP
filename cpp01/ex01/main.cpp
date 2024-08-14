#include "Zombie.hpp"

Zombie	*zombieHorde(std::string name, int N);

int main(void){

	int i = 0;
	int n = 5;

	if (n <= 0)
		return 1;
	Zombie *horde = zombieHorde("Betis", n);
	while (i < n)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return 0;
}
