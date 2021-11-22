#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form() {

	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("Presidential Pardon Form", 25, 5),
	_target(target) {

	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	Form(src) {

	_target = src._target;

	return ;
}

PresidentialPardonForm const &	PresidentialPardonForm::operator = (PresidentialPardonForm const & rhs) {

	Form::operator = (rhs);
	_target = rhs._target;

	return *this;
}

void	PresidentialPardonForm::run(void) const {

	std::cout	<< _target << " has been pardoned by Zafod Beeblebrox."
				<< std::endl;

	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

	return ;
}
