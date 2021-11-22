#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern(void) {

	_forms[0].represents = "shrubbery creation";
	_forms[0].form_ptrs = &createShrubbery;
	_forms[1].represents = "robotomy request";
	_forms[1].form_ptrs = &createRoboRequest;
	_forms[2].represents = "presidential pardon";
	_forms[2].form_ptrs = &createPardon;

	return ;
}

Intern::Intern(Intern const & src) {

	*this = src;

	return ;
}

Intern const &	Intern::operator = (Intern const & rhs) {

	for (int i = 0; i < fMax; i++) {
		this->_forms[i] = rhs._forms[i];
	}

	return *this;
}

Form *			Intern::makeForm(std::string form, std::string target) {

	for (int i = 0; i < fMax; i++) {
		if (form == _forms[i].represents) {
			std::cout << "Intern creates " << form << " form" << std::endl;
			return _forms[i].form_ptrs(target);
		}
	}
	std::cout << "Intern cannot find necessary form" << std::endl;

	return NULL;
}

Form *			Intern::createShrubbery(std::string target) {

	return new ShrubberyCreationForm(target);
}

Form *			Intern::createRoboRequest(std::string target) {

	return new RobotomyRequestForm(target);
}

Form *			Intern::createPardon(std::string target) {

	return new PresidentialPardonForm(target);
}

Intern::~Intern(void) {

	return ;
}
