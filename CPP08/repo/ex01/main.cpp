#include "span.hpp"

#define MAX_ELEMENTS 1000000

int main(void) {
	{
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	{
		Span	s(4);

		std::cout	<< "========= Testing S size array =========" << std::endl;
		try {
			s.addNumber(-3);
			s.addNumber(21);
			s.addNumber(21);
			s.addNumber(2);
			s.addNumber(-42);
			s.addNumber(-42);
		}
		catch (std::exception & e) {
			std::cout	<< e.what() << std::endl;
		}

		std::cout	<< s.shortestSpan() << " shortest span" << std::endl;
		std::cout	<< s.longestSpan() << " longest span" << std::endl
					<< std::endl;


		Span				m(21);
		std::vector<int>	sArray = s.getArray();

		std::cout	<< "========= Testing M size array =========" << std::endl;
		try {
			m.addRange(sArray.begin(), sArray.end());
			m.addNumber(INT_MAX);
			m.addRange(-3, 1);
			m.addNumber(INT_MIN);
			m.addRange(s);
			m.addNumber(INT_MAX);
			m.addRange(12, 7);
		}
		catch (std::exception & e) {
			std::cout	<< e.what() << std::endl;
		}
		std::cout	<< "m's size is " << m.getSize() << std::endl << m
					<< std::endl;
		std::cout	<< m.shortestSpan() << " shortest span" << std::endl;
		std::cout	<< m.longestSpan() << " longest span" << std::endl
					 << std::endl;


		Span				l(MAX_ELEMENTS);
		std::vector<int>	random;

		std::cout	<< "========= Testing L size array =========" << std::endl;
		std::srand(std::time(NULL));

		for (int i = 0; i < MAX_ELEMENTS; i++) {
			random.push_back(std::rand());
		}
		l.addRange(random.begin(), random.end());
		std::cout	<< l.shortestSpan() << " shortest span" << std::endl;
		std::cout	<< l.longestSpan() << " longest span" << std::endl;
	}

	return 0;
}
