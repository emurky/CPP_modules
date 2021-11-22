#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	upgradeBureaucrat(Bureaucrat & b, int grades) {

	for (int i = 0; i < grades; i++) {
		b.incrementGrade();
	}
	std::cout	<< b.getName() << " was upgraded!" << std::endl
				<< b << std::endl;

	return ;
}

int	main(void) {

	Bureaucrat	emurky("Safar", 142);

	ShrubberyCreationForm	garden("Garden");
	RobotomyRequestForm		code("Code writing");
	PresidentialPardonForm	craios("Craios");

	std::cout << std::endl << emurky << std::endl;
	emurky.signForm(garden);
	emurky.signForm(garden);
	emurky.executeForm(garden);
	upgradeBureaucrat(emurky, 10);
	emurky.executeForm(garden);

	std::cout << std::endl << emurky << std::endl;
	emurky.signForm(code);
	upgradeBureaucrat(emurky, 85);
	emurky.signForm(code);
	emurky.executeForm(code);
	upgradeBureaucrat(emurky, 21);
	std::cout << std::endl;
	emurky.executeForm(code);
	std::cout << std::endl;

	upgradeBureaucrat(emurky, 21);
	emurky.signForm(craios);
	emurky.executeForm(craios);
	std::cout << std::endl;

	return 0;
}
