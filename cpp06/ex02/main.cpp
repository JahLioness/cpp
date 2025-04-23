#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void) {
	int rando = rand();
	if (rando % 3 == 0)
		return (new C());
	else if (rando % 2 == 0)
		return (new B());
	else
		return (new A());
}

void	identify(Base *p) {
	if (A *a = dynamic_cast<A *>(p))
		std::cout << "Class of A type" << std::endl;
	else if (B *b = dynamic_cast<B *>(p))
		std::cout << "Class of B type" << std::endl;
	else
		std::cout << "Class of C type" << std::endl;
}

void	identify(Base &p) {
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "Class of A type" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "Class of B type" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "Class of C type" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{}
}

int main(void)
{
	std::srand(time(NULL));
	Base *class1= generate();
	Base *class2 = generate();
	Base *class3 = generate();

	identify(class1);
	identify(class2);
	identify(class3);
	std::cout << std::endl;

	identify(*class1);
	identify(*class2);
	identify(*class3);
	std::cout << std::endl;

	delete class1;
	delete class2;
	delete class3;
	return (0);
}