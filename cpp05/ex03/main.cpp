#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void){

	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat bur("Pepe", 1);

	rrf = someRandomIntern.makeForm("Presidential Pardon", "Bender");
	bur.signForm(*rrf);
	bur.executeForm(*rrf);
	delete rrf;

	rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
	bur.signForm(*rrf);
	bur.executeForm(*rrf);
	delete rrf;

	rrf = someRandomIntern.makeForm("Shrubbery Creation", "Bender");
	bur.signForm(*rrf);
	bur.executeForm(*rrf);
	delete rrf;

	rrf = someRandomIntern.makeForm("asdfsadf", "Bender");

	return 0;
}
