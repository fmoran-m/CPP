#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137, FALSE) {
	this->_target = "target";
//	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, FALSE) {
	this->_target = target;
//	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName(), 145, 137, FALSE){
	*this = src;
//	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
//	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	this->_target = rhs.getTarget();
	this->setSignBool(rhs.getSignBool());
//	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const{
	return (this->_target);
}

std::string ShrubberyCreationForm::getRequest(void) const{
	return ("shrubbery creation");
}
void ShrubberyCreationForm::executeThis(void) const{

	std::ofstream ofs(this->getTarget().c_str());

	ofs << "           .     .  .      +     .      .          ." << std::endl;
    ofs << "     .       .      .     #       .           ." << std::endl;
    ofs << "        .      .         ###            .      .      ." << std::endl;
    ofs << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
    ofs << "          .      . \"####\"###\"####\"  ." << std::endl;
    ofs << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
    ofs << "  .             \"#########\"#########\"        .        ." << std::endl;
    ofs << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
    ofs << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
    ofs << "                .\"##\"####\"\"####\"##\"           .      ." << std::endl;
    ofs << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
    ofs << "      .     \"#######\"##\"####\"##\"#######\"      .     ." << std::endl;
    ofs << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
    ofs << "            .     \"      000      \"    .     ." << std::endl;
    ofs << "       .         .   .   000     .        .       ." << std::endl;
    ofs << ".. .. ..................O000O........................ ...... ..." << std::endl;
	return;
}

ShrubberyCreationForm *ShrubberyCreationForm::clone(void){
	ShrubberyCreationForm *clone = new ShrubberyCreationForm(*this);
	return (clone);
}
