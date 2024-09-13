#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource &operator=(const MateriaSource &rhs);
	~MateriaSource();
	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);
private:
	AMateria *grimoire[4];
};
#endif
