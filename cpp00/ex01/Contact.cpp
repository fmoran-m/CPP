#include "Contact.hpp"

Contact::Contact(void){
	return;
}

Contact::~Contact(void){
	return;
}

std::string	Contact::getName() const{

	return (_name);
}

std::string	Contact::getLastName() const{

	return (_lastName);
}

std::string	Contact::getNickname() const{

	return (_nickname);
}

std::string	Contact::getPhoneNumber() const{

	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret() const{

	return (_darkestSecret);
}

void	Contact::setName(std::string &name){

	_name = name;
}

void	Contact::setLastName(std::string &lastName){

	_lastName = lastName;
}

void	Contact::setNickname(std::string &nickname){

	_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string &phoneNumber){

	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string &darkestSecret){

	_darkestSecret = darkestSecret;
}
