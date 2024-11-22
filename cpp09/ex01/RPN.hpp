/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:07 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/11/22 13:50:10 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <list>

class RPN {
	public:
		RPN(void);
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		~RPN(void);

		void	calculateExpression(std::string argvStr);
	private:
		std::stack<long long int, std::list<long long int> > rpnStack;

		void				parseToken(std::string token);
		void				calculateNewValue(std::string token);
		void				addTokenToStack(std::string token);
};
#endif
