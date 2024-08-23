#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(const ScavTrap &src);
	ScavTrap &operator=(const ScavTrap &cpy);

	void	attack(const std::string &target);

	void	guardGate(void);

	~ScavTrap();

};
#endif
