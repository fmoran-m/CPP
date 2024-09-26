#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>

# define	MIN_GRADE 150
# define	MAX_GRADE 1
# define	TRUE 1
# define	FALSE 0 

class Bureaucrat;

class AForm {

	private:
		std::string const	_name;
		int			const	_signGrade;
		int			const	_executeGrade;
		bool				_signBool;	

	public:
		AForm(void);
		AForm(std::string const name, int signGrade,
				int executeGrade, bool signBool);
		AForm(AForm const &src);
		AForm &operator=(AForm const &rhs);
		virtual ~AForm(void);

		std::string const	getName(void) const;
		int					getSignGrade(void) const;	
		int					getExecuteGrade(void) const;	
		bool				getSignBool(void) const;	
		void				setSignBool(bool signBool);

		void				beSigned(Bureaucrat &bur);
		void				execute(Bureaucrat const &executor)	const;
		virtual AForm		*clone(void) = 0;
		virtual std::string getRequest(void) const = 0;
		virtual void		executeThis(void) const = 0;


	class GradeTooHighException : public std::exception{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char *what() const throw();
	};

	class AlreadySignedException : public std::exception{
		public:
			virtual const char *what() const throw();
	};

	class SignatureFailureException : public std::exception{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, AForm const &rhs);

#endif
