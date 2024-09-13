#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		grimoire[i] = NULL;
	return;
}

MateriaSource::MateriaSource(const MateriaSource &src){
	*this = src;
	return;
}
MateriaSource &MateriaSource::operator=(const MateriaSource &rhs){
	for (int i = 0; i < 4; i++)
		grimoire[i] = rhs.grimoire[i];
	return (*this);
}
MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
	{
		if (grimoire[i])
		{
			delete grimoire[i];
			grimoire[i] = NULL;
		}
	}
	return;
}

void	MateriaSource::learnMateria(AMateria* materia){
	for (int i = 0; i < 4; i++){
		if (!grimoire[i])
		{
			this->grimoire[i] = materia;
			return;
		}
		std::cout << "Full inventory" << std::endl;
		delete materia;
		return;
	}
}

AMateria *MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (grimoire[i] && grimoire[i]->getType() == type)
			return (grimoire[i]->clone());
	}
	std::cout << "Material Type does not exist" << std::endl;
	return (NULL);
}
