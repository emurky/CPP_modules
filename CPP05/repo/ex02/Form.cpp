#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) :
	_name("none"),
	_sign_grade(150),
	_exec_grade(150),
	_signed(false) {

	return ;
}

Form::Form(std::string name, int signGrade, int execGrade) :
	_name(name),
	_sign_grade(signGrade),
	_exec_grade(execGrade),
	_signed(false) {

	if (_sign_grade < 1 || _exec_grade < 1) {
		throw Form::GradeTooHighException();
	}
	else if (_sign_grade > 150 || _exec_grade > 150) {
		throw Form::GradeTooLowException();
	}

	return ;
}

Form::Form(Form const & src) :
	_name(src._name),
	_sign_grade(src._sign_grade),
	_exec_grade(src._exec_grade),
	_signed(src._signed) {

	return ;
}

std::ostream &		operator << (std::ostream & out, Form const & form) {

	out	<< form.getName()
		<< " could be signed by grade " << form.getSignGrade()
		<< ", executed by grade " << form.getExecGrade()
		<< ", and currently is "
		<< (form.getIsSigned() ? "signed" : "not signed");

	return out;
}

Form const &		Form::operator = (Form const & rhs) {

	this->_signed = rhs._signed;

	return *this;
}

std::string			Form::getName(void) const {

	return _name;
}

int					Form::getSignGrade(void) const {

	return _sign_grade;
}

int					Form::getExecGrade(void) const {

	return _exec_grade;
}

bool				Form::getIsSigned(void) const {

	return _signed;
}

void				Form::beSigned(Bureaucrat const & bureaucrat) {

	if (bureaucrat.getGrade() > this->_sign_grade) {
		throw GradeTooLowException();
		return ;
	}
	if (_signed == true) {
		std::cout	<< bureaucrat.getName() << " could not sign " << _name
					<< " because it is already signed" << std::endl;
		return ;
	}
	std::cout	<< _name << " is signed by " << bureaucrat.getName()
				<< std::endl;
	this->_signed = true;

	return;
}

void				Form::execute(Bureaucrat const & executor) const {

	if (executor.getGrade() > this->_exec_grade) {
		throw GradeTooLowException();
		return ;
	}
	if (this->_signed == false) {
		std::cout	<< _name << " needs to be signed first" << std::endl;
		return ;
	}
	run();

	return ;
}

const char *		Form::GradeTooHighException::what() const throw() {

	return "Grade is too high";
}

const char *		Form::GradeTooLowException::what() const throw() {

	return "Grade is too low";
}

Form::~Form(void) {

	return ;
}
