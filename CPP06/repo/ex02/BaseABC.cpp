#include <iostream>

class	Base { public: virtual ~Base() {} };
class	A: public	Base { public: virtual ~A() {} };
class	B: public	Base { public: virtual ~B() {} };
class	C: public	Base { public: virtual ~C() {} };

Base *	generate(void);
void	identify(Base * p);
void	identify(Base & p);

int main(void) {

	Base *	p = generate();

	identify(p);
	identify(*p);

	delete p;

	return 0;
}

Base *	generate(void) {

	std::srand(time(NULL));
	int		switchClass = std::rand() % 3;

	switch (switchClass) {
		case 0:		return	new A;
		case 1:		return	new B;
		case 2:		return	new C;
	}

	return NULL;
}

void	identify(Base * p) {

	std::cout << "identify class by pointer" << std::endl;
	if (dynamic_cast<A *>(p)) {
		std::cout << 'A' << std::endl;
	}
	else if (dynamic_cast<B *>(p)) {
		std::cout << 'B' << std::endl;
	}
	else if (dynamic_cast<C *>(p)) {
		std::cout << 'C' << std::endl;
	}
}

void	identify(Base & r) {

	Base	b;

	std::cout << "identify class by reference" << std::endl;
	try {
		b = dynamic_cast<A &>(r);
		std::cout << 'A' << std::endl;
	}
	catch (std::exception & e) {}
	try {
		b = dynamic_cast<B &>(r);
		std::cout << 'B' << std::endl;
	}
	catch (std::exception & e) {}
	try {
		b = dynamic_cast<C &>(r);
		std::cout << 'C' << std::endl;
	}
	catch (std::exception & e) {}
}
