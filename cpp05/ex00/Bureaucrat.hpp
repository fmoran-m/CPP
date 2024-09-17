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

	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception{};

private:
	std::string const	_name;
	int					_grade;
};

#endif
