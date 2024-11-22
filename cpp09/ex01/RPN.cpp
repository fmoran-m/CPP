/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:04 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/11/22 13:55:01 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <climits>

RPN::RPN(void) {}
RPN::~RPN(void) {}
RPN::RPN(RPN const &src) {
	*this = src;
	return;
}
RPN &RPN::operator=(RPN const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	this->rpnStack = rhs.rpnStack;
	return (*this);
}

void	RPN::calculateExpression(std::string argvStr)
{
	std::stringstream split(argvStr);
	std::string token;

	try{
		while (split >> token)
		{
			this->parseToken(token);
			this->addTokenToStack(token);
		}
	}catch(std::exception &e){
		std::cerr << e.what() << std::endl;
		return;
	}
	if (rpnStack.size() > 1){
		std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << rpnStack.top() << std::endl;
	return;
}

//PRIVATE METHODS

void	RPN::parseToken(std::string token)
{
	std::string operators = "+-*/";
	if (token.length() > 1) 
		throw std::logic_error("Error");
	if (!std::isdigit(*token.begin()) && operators.find(*token.begin()) == std::string::npos)
		throw std::logic_error("Error");
	return;
}

void	RPN::addTokenToStack(std::string token)
{
	long long int value;

	if (isdigit(*token.begin()))
	{
		std::istringstream(token) >> value;
		this->rpnStack.push(value);
	}
	else
		calculateNewValue(token);
	return;
}

void	RPN::calculateNewValue(std::string token)
{
	long long int a;
	long long int b;

	if (rpnStack.empty())
		throw std::logic_error("Error");
	a = rpnStack.top();
	rpnStack.pop();
	if (rpnStack.empty())
		throw std::logic_error("Error");
	b = rpnStack.top();
	rpnStack.pop();
	switch(*token.begin()){
		case '+':
		{
			if (b + a > INT_MAX)
				throw std::overflow_error("Error: overflow");
			rpnStack.push(b + a);
			return;
		}
		case '-':
		{
			if (b - a < INT_MIN)
				throw std::overflow_error("Error: overflow");
			rpnStack.push(b - a);
			return;
		}
		case '*':
		{
			if (b * a > INT_MAX)
				throw std::overflow_error("Error: overflow");
			rpnStack.push(b * a);
			return;
		}
		case '/':
		{
			if (b / a > INT_MIN)
				throw std::overflow_error("Error: overflow");
			if (a == 0)
				throw std::logic_error("Error");
			rpnStack.push(b / a);
			return;
		}
	}
	return;
}