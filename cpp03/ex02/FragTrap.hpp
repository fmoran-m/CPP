#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &cpy);

	void	attack(const std::string &target);

	void	highFivesGuys(void);

	~FragTrap();

};
#endif
