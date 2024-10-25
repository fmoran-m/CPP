#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	std::vector<int> vector;

	for (int i = 0; i <= 20; i++)
		vector.push_back(i);

	std::cout << "----Number Exists----" << std::endl;
	try{
		std::cout << *(easyfind(vector, 20)) << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "----Number Does Not Exist----" << std::endl;
	try{
		std::cout << *(easyfind(vector, 21)) << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::list<int> list;

	for (int i = 0; i <= 20; i++)
		list.push_back(i);

	std::cout << "----Number Exists----" << std::endl;
	try{
		std::cout << *(easyfind(list, 20)) << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "----Number Does Not Exist----" << std::endl;
	try{
		std::cout << *(easyfind(list, 21)) << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::deque<int> deque;

	for (int i = 0; i <= 20; i++)
		deque.push_back(i);

	std::cout << "----Number Exists----" << std::endl;
	try{
		std::cout << *(easyfind(deque, 20)) << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "----Number Does Not Exist----" << std::endl;
	try{
		std::cout << *(easyfind(deque, 21)) << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
