#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data *ptr = new Data;

	ptr->a = 0;
	ptr->b = 0;
	ptr->c = 0;

	uintptr_t num = Serializer::serialize(ptr);

	std::cout << num << std::endl;

	if (ptr == Serializer::deserialize(num)){
		std::cout << "Success" << std::endl;
	}

	std::cout << Serializer::deserialize(num) << std::endl;

	delete ptr;

	return 0;
}
