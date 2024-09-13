#ifndef CURE_HPP
# define CURE_HPP
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {

public:
	Cure();
	Cure(std::string const &type);
	Cure(const Cure &src);
	Cure &operator=(const Cure &rhs);
	~Cure();

	Cure*				clone() const;
	void				use(std::string const &name) const;

protected:
	std::string const type;
};
#endif
