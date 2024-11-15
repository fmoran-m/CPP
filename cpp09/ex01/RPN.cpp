#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
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
	if (isOverflow(a, b, token))
		throw std::logic_error("Error");
	switch(*token.begin()){
		case '+':
		{
			rpnStack.push(b + a);
			return;
		}
		case '-':
		{
			rpnStack.push(b - a);
			return;
		}
		case '*':
		{
			rpnStack.push(b * a);
			return;
		}
		case '/':
		{
			if (a == 0)
				throw std::logic_error("Error");
			rpnStack.push(b / a);
			return;
		}
	}
	return;
}

bool RPN::isOverflow(long long int a, long long int b, std::string token)
{
	switch (*token.begin())
	{
		case '+': 
		{
			if ((b > 0 && a > LLONG_MAX - b) || (b < 0 && a < LLONG_MIN - b))
				return true;
			break;
		}
		case '-': 
		{
			if ((b < 0 && a > LLONG_MAX + b) || (b > 0 && a < LLONG_MIN + b))
				return true;
			break;
		}
		case '*': 
		{
			if (a > 0)
			{
				if ((b > 0 && a > LLONG_MAX / b) || (b < 0 && a > LLONG_MIN / b))
					return true;
			}
			else if (a < 0)
			{
				if ((b > 0 && a < LLONG_MIN / b) || (b < 0 && a < LLONG_MAX / b))
					return true;
			}
			break;
		}
		case '/': 
		{
			if (a == LLONG_MIN && b == -1)
				return true;
			break;
		}
	}
	return false;
}