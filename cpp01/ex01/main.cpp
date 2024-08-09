#include "Zombie.hpp"

Zombie	*zombieHorde(int N);

int main(void){

	int i = 0;
	int n = 5;

	Zombie *horde = zombieHorde(n);
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;;
	return 0;
}
