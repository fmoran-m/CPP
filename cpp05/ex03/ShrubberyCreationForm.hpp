#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm(void);

		void					executeThis(void) const;
		std::string				getTarget(void) const;
		std::string				getRequest(void) const;

		ShrubberyCreationForm	*clone(void);

	private:
		std::string _target;
};
#endif
