#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T container, int number){

	typename T::iterator it = std::find(container.begin(), container.end(), number);

	if (it == container.end())
		throw std::logic_error("Error: incorrect number");
	return (it);
}
