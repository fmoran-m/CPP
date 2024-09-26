#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(Intern const &src);
		Intern &operator=(Intern const &rhs);
		~Intern(void);

		AForm *makeForm(std::string request, std::string target);
	private:
		std::string	_formatRequest(std::string request);
		int			_checkRequest(AForm **forms, std::string request);

	class FormNotFoundException : public std::exception{
		public:
			virtual const char *what() const throw();
	};

};

#endif
