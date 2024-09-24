#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main(void)
{
	PresidentialPardonForm a("Betis");
	Bureaucrat bur("Pepe", 1);
	bur.executeForm(a);
	bur.signForm(a);
	bur.signForm(a);
	bur.executeForm(a);
	return 0;
}
