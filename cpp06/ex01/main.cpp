#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data *ptr = new Data;

	uintptr_t num = Serializer::serialize(ptr);

	std::cout << num << std::endl;
	std::cout << Serializer::deserialize(num) << std::endl;

	delete ptr;

	return 0;
}
