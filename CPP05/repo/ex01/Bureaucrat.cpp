#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("none"), _grade(150) {

	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name), _grade(grade) {

	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->_grade = grade;
	}

	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name) {

	*this = src;

	return ;
}

Bureaucrat const &	Bureaucrat::operator = (Bureaucrat const & rhs) {

	this->_grade = rhs._grade;

	return *this;
}

std::ostream &		operator << (std::ostream & out, Bureaucrat const & bc) {

	out	<< bc.getName() << " is a bureaucrat graded " << bc.getGrade();

	return out;
}

std::string			Bureaucrat::getName(void) const {

	return _name;
}

int					Bureaucrat::getGrade(void) const {

	return _grade;
}

void				Bureaucrat::incrementGrade(void) {

	if (_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		_grade--;
	}

	return ;
}

void				Bureaucrat::decrementGrade(void) {

	if (_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		_grade++;
	}

	return ;
}

void				Bureaucrat::signForm(Form & form) const {

	if (form.getIsSigned()) {
		std::cout	<< _name << " could not sign " << form.getName()
					<< " because it is already signed" << std::endl;
		return ;
	}
	try {
		form.beSigned(*this);
	}
	catch (Form::GradeTooLowException & fe) {
		std::cout	<< form.getName() << " could not be signed by "
					<< _name << " because " << _name << "'s grade is too low"
					<< std::endl;
		return ;
	}
	std::cout 	<< _name << " successfully signs " << form.getName()
				<< std::endl;

	return ;
}

const char *		Bureaucrat::GradeTooHighException::what() const throw() {

	return "Grade is too high";
}

const char *		Bureaucrat::GradeTooLowException::what() const throw() {

	return "Grade is too low";
}

Bureaucrat::~Bureaucrat(void) {

	return;
}
