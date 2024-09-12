#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class AMateria{

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &src);
	AMateria &operator=(const AMateria &rhs);
	virtual ~AMateria();

	virtual AMateria* clone() const = 0;
	std::string const & getType(void) const;

protected:
	std::string const type;
};
#endif
