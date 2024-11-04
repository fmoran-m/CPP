#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN {
	public:
		RPN(void);
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		~RPN(void);

		void	calculateExpression(std::string argvStr);
	private:
		std::stack<long long int> rpnStack;

		void				parseToken(std::string token);
		void				calculateNewValue(std::string token);
		void				addTokenToStack(std::string token);
};
#endif
