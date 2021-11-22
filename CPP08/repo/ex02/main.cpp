#include "mutantstack.hpp"
#include <iostream>

int main(void) {
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		while (!s.empty()) {
			std::cout	<< s.top() << std::endl;
			s.pop();
		}
	}
	{
		MutantStack<std::string>					last;
		MutantStack<std::string>::reverse_iterator	it;

		last.push("XP");
		last.push("9660 ");
		last.push("costs ");
		last.push("exercise ");
		last.push("This ");
		last.push("do not count this please");

		std::cout	<< std::endl;
		std::cout	<< "Mutant's size is " << last.size() << std::endl;
		std::cout	<< "Mutant's top is " << "\"" << last.top() << "\""
					<< std::endl << std::endl;
		last.pop();

		for (it = last.rbegin(); it < last.rend(); it++) {
			std::cout	<< *it;
		}
		std::cout	<< std::endl;
	}

	return 0;
}
