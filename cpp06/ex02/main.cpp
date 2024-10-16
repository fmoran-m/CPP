#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	for (int i = 0; i < 3; i++){
		Base *ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	return 0;
}
