#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "AForm.hpp"
# include <string>

# define	MIN_GRADE 150
# define	MAX_GRADE 1
# define	TRUE 1
# define	FALSE 0 

class Bureaucrat {

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	~Bureaucrat(void);

	void				promotion(void);
	void				relegation(void);
	void				signForm(AForm &form);

	std::string const	getName(void) const;
	int					getGrade(void) const;	

	class GradeTooHighException : public std::exception{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char *what() const throw();
	};

private:
	std::string const	_name;
	int					_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs);
#endif
