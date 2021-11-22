#include "iter.hpp"
#include <iostream>

void	stringPerLine(std::string const & element) {

	std::cout << element << std::endl;
}

void	ppPrimes(int const & prime) {

	std::cout << prime << " ";
}

int main(void) {

	std::string	hello[2] = { "Hello There", "General Kenobi" };
	int			prime[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };

	iter(hello, 2, stringPerLine);
	std::cout << std::endl;
	iter(prime, 9, ppPrimes);
	std::cout << std::endl;

	return 0;
}
