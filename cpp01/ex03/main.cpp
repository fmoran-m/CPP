#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("Sword");
		HumanA bob("Bob", club);
		HumanB jim("Jim");
		jim.setWeapon(club);
		bob.attack();
		jim.attack();
		club.setType("Spike");
		bob.attack();
		jim.attack();
	}

	{
		Weapon club = Weapon("Gun");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("MachineGun");
		jim.attack();
	}
	return 0;
}
