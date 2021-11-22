#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void) {

	{
		std::vector<int>	v_ints;

		v_ints.push_back(12);
		v_ints.push_back(5);
		v_ints.push_back(1024);
		v_ints.push_back(-1);
		v_ints.push_back(21);
		v_ints.push_back(0);

		try {
			std::cout	<< *easyfind(v_ints, 21)
						<< " - value pointed by returned iterator" << std::endl;
			std::cout	<< *easyfind(v_ints, -1)
						<< " - value pointed by returned iterator" << std::endl;
			std::cout	<< *easyfind(v_ints, -42)
						<< " - value pointed by returned iterator" << std::endl;
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	{
		std::list<int>	l_ints;

		l_ints.push_back(12);
		l_ints.push_back(21);

		try {
			std::cout	<< *easyfind(l_ints, 21)
						<< " - value pointed by returned iterator" << std::endl;
			std::cout	<< *easyfind(l_ints, 12)
						<< " - value pointed by returned iterator" << std::endl;
			std::cout	<< *easyfind(l_ints, -42)
						<< " - value pointed by returned iterator" << std::endl;
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
