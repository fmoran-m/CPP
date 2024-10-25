#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

int main(void)
{
	std::cout << "----Mutant Stack - Main----" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Mstack: Top element: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Mstack: Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "Elements inside Mstack: " << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "----List - Main----" << std::endl;
	{
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << "Mstack: Top element: " << list.back() << std::endl;
		list.pop_back();
		std::cout << "Mstack: Size: " << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "Elements inside Mstack: " << *it << std::endl;
			++it;
		}
	}
	std::cout << "----Const Mutant Stack - Main----" << std::endl;
	{
		std::deque<int> mydeque (5, 10);  
		const MutantStack<int> mstack(mydeque);
		std::cout << "Mstack: Size: " << mstack.size() << std::endl;
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "Elements inside Mstack: " << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	return 0;
}
