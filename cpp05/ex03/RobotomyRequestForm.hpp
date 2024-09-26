#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
		~RobotomyRequestForm(void);

		void				executeThis(void) const;
		std::string			getTarget(void) const;
		std::string			getRequest(void) const;

		RobotomyRequestForm	*clone(void);

	private:
		std::string _target;
};

#endif
