#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _it(0), _loopFlag(0){
	return;
}

PhoneBook::~PhoneBook(void){
	return;
}

bool	PhoneBook::_validateInputNumber(std::string input) const{

	int	i = 0;
	int	inNumber;

	if (input == "")
		return false;
	if (input.length() > 1)
	{
		std::cout << "Please, select a valid index." << std::endl;
		return false;
	}
	for (char c : input)
	{
		if (!std::isdigit(c))
		{
			std::cout << "Please, select a valid index." << std::endl;
			return false;
		}
	}

	while( i < 8 && _contacts[i].getName() != "")
		i++;
	inNumber = std::stoi(input);
	if (inNumber < 1 || inNumber > i)
	{
		std::cout << "Please, select a valid index" << std::endl;
		return false;
	}
	return true;
}

bool	PhoneBook::_printTable(void) const {

	int	i = 0;

	if (_contacts[0].getName() == "")
	{
		std::cout << "Add some contacts!" << std::endl;
		return false;
	}
	std::cout << std::right;
	std::cout << std::endl;
	std::cout << std::setfill ('-') << std::setw(45) << "" << std::endl;
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "Index";
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "First Name";
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "Last Name";
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10) << "Nickname";
	std::cout << '|' << std::endl;
	std::cout << std::setfill ('-') << std::setw(45) << "" << std::endl;

	while (i < 8 && _contacts[i].getName() != "")
	{
		std::cout << std::right;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i + 1 << "|";
		if (_contacts[i].getName().length() > 10)
		{
			std::cout << std::setfill(' ') << std::setw(9); 
			std::cout << _contacts[i].getName().substr(0, 9) << ".|";
		}
		else
		{
			std::cout << std::setfill(' ') << std::setw(10); 
			std::cout << _contacts[i].getName().substr(0, 10) << "|";
		}
		if (_contacts[i].getLastName().length() > 10)
		{
			std::cout << std::setfill(' ') << std::setw(9);
			std::cout << _contacts[i].getLastName().substr(0, 9) << ".|";
		}
		else
		{
			std::cout << std::setfill(' ') << std::setw(10);
			std::cout << _contacts[i].getLastName().substr(0, 10) << "|";
		}
		if (_contacts[i].getNickname().length() > 10)
		{
			std::cout << std::setfill(' ') << std::setw(9);
			std::cout << _contacts[i].getNickname().substr(0, 9) << ".|" << std::endl;
		}
		else
		{
			std::cout << std::setfill(' ') << std::setw(10);
			std::cout << _contacts[i].getNickname().substr(0, 10) << "|" << std::endl;
		}
		std::cout << std::setfill ('-') << std::setw(45) << "" << std::endl;
		i++;
	}
	std::cout << std::endl;
	return true;
}

bool PhoneBook::add(){

	std::string input;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return false;
	while(input == ""){
		std::cout << "First name: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return false;
	}
	_contacts[_it].setName(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return false;
	while(input == ""){
		std::cout << "Last name: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return false;
	}
	_contacts[_it].setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return false;
	while(input == ""){
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return false;
	}
	_contacts[_it].setNickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	if(std::cin.eof())
		return false;
	while(input == ""){
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return false;
	}
	_contacts[_it].setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return false;
	while(input == ""){
		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return false;
	}
	_contacts[_it].setDarkestSecret(input);

	_it++;
	if (_it == 8)
		_it = 0;

	std::cout << std::endl;

	return true;
}

bool PhoneBook::search() const{

	int	inNumber;
	std::string	input;

	if (_printTable() == false)
		return true;
	
	std::cout << "Select a number: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return false;

	while (!_validateInputNumber(input)){
		std::cout << "Select a number: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return false;
	}

	inNumber = std::stoi(input);
	std::cout << std::endl;
	std::cout << "First name: ";
	std::cout << _contacts[inNumber - 1].getName() << std::endl;
	std::cout << "Last name: ";
	std::cout << _contacts[inNumber - 1].getLastName() << std::endl;
	std::cout << "Nickname: ";
	std::cout << _contacts[inNumber - 1].getNickname() << std::endl;
	std::cout << "Phone number: ";
	std::cout << _contacts[inNumber - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << _contacts[inNumber - 1].getDarkestSecret() << std::endl;
	std::cout << std::endl;

	return true;
}

void PhoneBook::enterCommand(){

	std::string input;

	while(!_loopFlag)
	{
		std::cout << "Insert command: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			_loopFlag = 1;
		else if (input == "ADD"){
			if (add() == false)
			_loopFlag = 1;
		}
		else if (input == "SEARCH"){
			if (search() == false)
			_loopFlag = 1;
		}
		else if (input == "EXIT")
			_loopFlag = 1;
		else if (input == "")
			continue;
	}
	std::cout << std::endl;
	return;
}
