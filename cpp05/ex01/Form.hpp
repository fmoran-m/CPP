#ifndef FORM_HPP
# define FORM_HPP
# include <string>

class Bureaucrat;

class Form {

	private:
		std::string const	_name;
		int			const	_signGrade;
		int			const	_executeGrade;
		bool				_signBool;	

	public:
		Form(void);
		Form(std::string const name, int signGrade,
				int executeGrade, bool signBool);
		Form(Form const &src);
		Form &operator=(Form const &rhs);
		~Form(void);

		std::string const	getName(void) const;
		int					getSignGrade(void) const;	
		int					getExecuteGrade(void) const;	
		bool				getSignBool(void) const;	

		void				beSigned(Bureaucrat &bur);

	class GradeTooHighException : public std::exception{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, Form const &rhs);

#endif
