#include <algorithm>
#include <iostream>

class IntegerNotFoundException : public std::exception{
	public:
		virtual const char *what() const throw(){
			return ("Error: integer not found");
		};
};

template <typename T>
int easyfind(T container, int number){
	int found = *(std::find(container.begin(), container.end(), number));

	std::cout << "found: " << found << std::endl;
	std::cout << "number: " << number << std::endl;
	if (found !=  )
		throw IntegerNotFoundException();
	return (found);
}