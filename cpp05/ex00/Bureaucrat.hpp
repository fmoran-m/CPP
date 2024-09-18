#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat {

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	~Bureaucrat(void);

	void				promotion(void);
	void				relegation(void);

	std::string const	getName(void) const;
	int					getGrade(void) const;	

	class GradeTooHighException : public std::exception{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			const char *what() const throw();
	};

private:
	std::string const	_name;
	int					_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs);
#endif
