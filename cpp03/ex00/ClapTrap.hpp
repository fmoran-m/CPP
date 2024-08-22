#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &cpy);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	unsigned int	getHitPoints(void);
	unsigned int	getEnergyPoints(void);
	unsigned int	getAttackDamage(void);

private:

	std::string const	_name;
	unsigned int		_hitPoints;
	unsigned int		_energyPoints;
	unsigned int		_attackDamage;
};
#endif
