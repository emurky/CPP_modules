#include <iostream>
#include "Bureaucrat.hpp"


int	main(void) {

	try {
		Bureaucrat scavtrap("ScavTrap", 421);
		std::cout	<< scavtrap << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try {
		Bureaucrat fragtrap("FragTrap", -21);
		std::cout	<< fragtrap << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try {
		Bureaucrat	cashier("Nina", 150);
		std::cout << cashier << std::endl;
		cashier.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try {
		Bureaucrat	manager("Margarita", 1);
		std::cout << manager << std::endl;
		manager.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	return 0;
}
