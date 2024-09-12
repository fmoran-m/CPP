#ifndef ICE_HPP
# define ICE_HPP
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {

public:
	Ice();
	Ice(std::string const &type);
	Ice(const Ice &src);
	Ice &operator=(const Ice &rhs);
	~Ice();

	std::string const	&getType(void) const;
	Ice*				clone() const;
	void				use(std::string const &name) const;

protected:
	std::string const	type;
};
#endif
