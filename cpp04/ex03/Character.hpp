#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter{
public:
	Character();
	Character(std::string const & name);
	Character(const Character &src);
	Character &operator=(const Character &rhs);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria *inventory[4];
private:
	std::string const & name;
	static const std::string defaultName;
};
#endif
