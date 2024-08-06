#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	bool	add(void);
	bool	search(void) const;
	void	enterCommand(void);

private:

	Contact _contacts[8];
	int		_it;
	bool	_validateInputNumber(std::string input) const;
	bool	_printTable(void) const;
};

#endif
