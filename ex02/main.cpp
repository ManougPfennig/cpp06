#include <iostream>
#include <random>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void){

	switch (rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void	identify(Base *p){

	if (p == NULL)
		return ;
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer type is   A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer type is   B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer type is   C" << std::endl;
}

void	identify(Base &p){

	try{A temp = dynamic_cast<A &>(p);
		std::cout << "Reference type is A" << std::endl;}
	catch(const std::exception &e){}

	try{B temp = dynamic_cast<B &>(p);
		std::cout << "Reference type is B" << std::endl;}
	catch(const std::exception &e){}

	try{C temp = dynamic_cast<C &>(p);
		std::cout << "Reference type is C" << std::endl;}
	catch(const std::exception &e){}
}

int	main( void )
{
	srand(time(NULL));

	Base	*rand = generate();
	identify(rand);
	identify(*rand);
	std::cout << "\n" << std::endl;

	Base	*rand2 = generate();
	identify(rand2);
	identify(*rand2);
	std::cout << "\n" << std::endl;

	Base	*rand3 = generate();
	identify(rand3);
	identify(*rand3);
	std::cout << "\n" << std::endl;
	return (0);
}