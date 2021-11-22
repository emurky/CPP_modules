#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form() {

	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("Robotomy Request Form", 72, 45),
	_target(target) {

	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	Form(src) {

	_target = src._target;

	return ;
}

RobotomyRequestForm const &	RobotomyRequestForm::operator = (RobotomyRequestForm const & rhs) {

	Form::operator = (rhs);
	_target = rhs._target;

	return *this;
}

void	RobotomyRequestForm::run(void) const {

	std::srand(time(NULL));
	int	random = std::rand();

	std::cout	<< "* BRR DRDRDRBBB RBBRBRRBBB BRRR *" << std::endl
				<< _target << " has " << (random % 2 ? "SUCCESSFULLY" : "NOT")
				<< " been robotomized" << std::endl
				<< "* BR BDRDRDRBRRUUUHH *" << std::endl;

	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

	return ;
}
