#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter{
public:
	Character();
	Character(std::string name);
	Character(const Character &src);
	Character &operator=(const Character &rhs);
	~Character();

	std::string const	&getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

private:
	AMateria			*inventory[4];
	std::string			name;
};
#endif
