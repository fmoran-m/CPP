#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap  {

public:

	DiamondTrap();
	DiamondTrap(std::string const &name);
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap &operator=(const DiamondTrap &cpy);

	void	attack(const std::string &target);

	void	whoAmI(void);

	~DiamondTrap();

private:

	std::string _name;

};
#endif
