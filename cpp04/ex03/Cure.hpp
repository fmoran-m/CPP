#ifndef CURE_HPP
# define CURE_HPP
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria {

public:
	Cure();
	Cure(std::string const &type);
	Cure(const Cure &src);
	Cure &operator=(const Cure &rhs);
	~Cure();

	Cure* clone() const;
	std::string const & getType(void) const;

protected:
	std::string const type;
};
#endif
