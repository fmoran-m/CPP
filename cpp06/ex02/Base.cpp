#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base(void) {
	return;
}

Base *generate(void){
	static int seed = 0;

	if (seed < 1){
		srand(time(NULL));
		seed++;
	}
	int n = (rand() % 3);
	
	if (n == 0)
		return (new A);
	if (n == 1)
		return (new B);
	return (new C);
}

void identify(Base *p){
    A *a = dynamic_cast<A *>(p);
	if (a){
		std::cout << "class A" << std::endl;
		return;
	}
    B *b = dynamic_cast<B *>(p);
	if (b){
		std::cout << "class B" << std::endl;
		return;
	}
    C *c = dynamic_cast<C *>(p);
	if (c){
		std::cout << "class C" << std::endl;
		return;
	}
}

void identify(Base &p){
	try{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "class A" << std::endl;
		return;
	}catch(std::exception &e){};
	try{
		B b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "class B" << std::endl;
		return;
	}catch(std::exception &e){};
	try{
		C c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "class C" << std::endl;
		return;
	}catch(std::exception &e){};
}
