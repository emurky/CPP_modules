#include "Contact.hpp"

#include <iostream>
#include <iomanip>

Contact::Contact ( void ) {

	return ;
}

void	Contact::setContact( void ) {

	std::cout << "first name:     ";
	std::getline(std::cin, this->_first_name);

	std::cout << "last name:      ";
	std::getline(std::cin, this->_last_name);

	std::cout << "nickname:       ";
	std::getline(std::cin, this->_nickname);

	std::cout << "phone number:   ";
	std::getline(std::cin, this->_phone_number);

	std::cout << "darkest secret: ";
	std::getline(std::cin, this->_darkest_secret);
}

void	Contact::print_formatted( std::string field ) const {

	if (field.length() > 10) {
		field = field.substr(0, 9) + ".";
	}
	std::cout << std::setw(10) << field;
}

void	Contact::printContactInLine( void ) const {

	print_formatted(this->_first_name);
	std::cout << '|';
	print_formatted(this->_last_name);
	std::cout << '|';
	print_formatted(this->_nickname);
	std::cout << std::endl;
}

void	Contact::printContact( void ) const {

	std::cout << "First name:     " << this->_first_name << std::endl;
	std::cout << "Last name:      " << this->_last_name << std::endl;
	std::cout << "Nickname:       " << this->_nickname << std::endl;
	std::cout << "Phone number:   " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << "..." << std::endl;
}

Contact::~Contact( void ) {

	return ;
}
