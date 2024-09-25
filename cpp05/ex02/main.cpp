#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main(void)
{
	//Correct sign and executor
	std::cout << "---ShrubberyCreationForm 1---" << std::endl;
	std::cout << std::endl;
	try{
		ShrubberyCreationForm form;
		Bureaucrat Signer("Signer", 100);
		Bureaucrat Executor("Executor", 100);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---ShrubberyCreationForm 2---" << std::endl;
	std::cout << std::endl;

	try{
		ShrubberyCreationForm form("form");
		Bureaucrat Signer("Signer", 151);
		Bureaucrat Executor("Executor", 100);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---ShrubberyCreationForm 3---" << std::endl;
	std::cout << std::endl;

	try{
		ShrubberyCreationForm form("form");
		Bureaucrat Signer("Signer", 100);
		Bureaucrat Executor("Executor", 151);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---ShrubberyCreationForm 4---" << std::endl;
	std::cout << std::endl;

	try{
		ShrubberyCreationForm form("form");
		Bureaucrat Signer("Signer", -1);
		Bureaucrat Executor("Executor", 100);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---ShrubberyCreationForm 5---" << std::endl;
	std::cout << std::endl;

	try{
		ShrubberyCreationForm form("form");
		Bureaucrat Signer("Signer", 100);
		Bureaucrat Executor("Executor", -1);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---ShrubberyCreationForm 6---" << std::endl;
	std::cout << std::endl;

	try{
		ShrubberyCreationForm form("form");
		Bureaucrat Signer("Signer", 146);
		Bureaucrat Executor("Executor", 100);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---ShrubberyCreationForm 7---" << std::endl;
	std::cout << std::endl;

	try{
		ShrubberyCreationForm form("form");
		Bureaucrat Signer("Signer", 100);
		Bureaucrat Executor("Executor", 138);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---RobotomyRequestForm 1---" << std::endl;
	std::cout << std::endl;
	try{
		RobotomyRequestForm form;
		Bureaucrat Signer("Signer", 40);
		Bureaucrat Executor("Executor", 40);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---RobotomyRequestForm 2---" << std::endl;
	std::cout << std::endl;
	try{
		RobotomyRequestForm form;
		Bureaucrat Signer("Signer", 73);
		Bureaucrat Executor("Executor", 40);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---RobotomyRequestForm 3---" << std::endl;
	std::cout << std::endl;
	try{
		RobotomyRequestForm form;
		Bureaucrat Signer("Signer", 40);
		Bureaucrat Executor("Executor", 46);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---PresidentialPardonForm 1---" << std::endl;
	std::cout << std::endl;
	try{
		PresidentialPardonForm form;
		Bureaucrat Signer("Signer", 1);
		Bureaucrat Executor("Executor", 1);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---PresidentialPardonForm 2---" << std::endl;
	std::cout << std::endl;
	try{
		PresidentialPardonForm form;
		Bureaucrat Signer("Signer", 26);
		Bureaucrat Executor("Executor", 1);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---PresidentialPardonForm 3---" << std::endl;
	std::cout << std::endl;
	try{
		PresidentialPardonForm form;
		Bureaucrat Signer("Signer", 1);
		Bureaucrat Executor("Executor", 6);
		Executor.executeForm(form);
		Signer.signForm(form);
		Signer.signForm(form);
		Executor.executeForm(form);
	}catch(std::exception &e){
		std::cout << "Main Error: " << e.what() << std::endl;
	}
return 0;
}
