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
	bool	search(void);
	void	enterCommand(void);

private:

	Contact _contacts[8];
	int		_it;
	bool	_validateInputNumber(std::string input);
	bool	_printTable(void);
};

#endif
