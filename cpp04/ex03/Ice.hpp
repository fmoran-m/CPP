#ifndef ICE_HPP
# define ICE_HPP
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria {

public:
	Ice();
	Ice(std::string const &type);
	Ice(const Ice &src);
	Ice &operator=(const Ice &rhs);
	~Ice();

	Ice* clone() const;
	std::string const & getType(void) const;

protected:
	std::string const type;
};
#endif
