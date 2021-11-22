#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main(void) {

	Form		school21("School 21 Certificate", 12, 1);
	Bureaucrat	lana("Lana", 1);
	Bureaucrat	olga("Olga", 2);
	Bureaucrat	nastya("Nastya", 42);

	try {
		Form	form1("form1", 0, 142);
	}
	catch (std::exception & e) {
		std::cout << "form1: " << e.what() << std::endl;
	}

	try {
		Form	form2("form2", 1, 172);
	}
	catch (std::exception & e) {
		std::cout << "form2: " << e.what() << std::endl << std::endl;
	}

	std::cout << school21 << std::endl;
	try {
		nastya.signForm(school21);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		lana.signForm(school21);
		olga.incrementGrade();
		olga.signForm(school21);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << school21 << std::endl;

	return 0;
}
