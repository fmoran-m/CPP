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
	int n = 0;
	n++;

	srand(time(NULL));
	n = (rand() % 3);
	
	if (n == 0)
		return (new A);
	if (n == 1)
		return (new B);
	return (new C);
}

void identify(Base *p){
	(void)p;
	//Dinamic Cast a puntero
	return;
}

void identify(Base &p){
	(void)p;
	//Identificacion directa?
	return;
}
