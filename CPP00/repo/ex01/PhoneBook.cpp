#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook( void ) {

	this->_count = 0;
	return ;
}

void	PhoneBook::addContact( void ) {

	Contact		temp;

	if (this->_count < contNum) {
		this->_contacts[_count].setContact();
		this->_count++;
	}
	else {
		std::cout << "We've run out of memory, you PhoneBook can contain only ";
		std::cout << contNum << " contacts. Replacing your oldest contact...";
		std::cout << std::endl;
		for (int i = 0; i < contNum - 1; i++) {
			this->_contacts[i] = this->_contacts[i + 1];
		}
		this->_contacts[contNum - 1].setContact();
	}
}

bool	PhoneBook::printContacts( void ) const {

	if (this->_count) {
		for (int i = 0; i < 43; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;
		this->_contacts[0].print_formatted("index");
		std::cout << "|";
		this->_contacts[0].print_formatted("first name");
		std::cout << '|';
		this->_contacts[0].print_formatted("last name");
		std::cout << '|';
		this->_contacts[0].print_formatted("nickname");
		std::cout << std::endl;
		for (int i = 0; i < 43; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;
		for (int i = 0; i < this->_count; i++) {
			std::cout << std::setw(10) << i + 1;
			std::cout << "|";
			this->_contacts[i].printContactInLine();
		}
		for (int i = 0; i < 43; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "There are no contacts yet. Add one with \"ADD\" command";
		std::cout << std::endl;
		return (false);
	}

	return (true);
}

void	PhoneBook::searchContact( void ) const {

	std::string		input;
	int				id;

	if (!PhoneBook::printContacts()) {
		return ;
	}
	std::cout << "Please enter desirable contact's ID to show full info: ";
	std::getline(std::cin, input);
	std::cout << std::endl;
	if (!PhoneBook::_str_isnum(input) ) {
		std::cout << "ID is not valid, please try again" << std::endl;
		std::cout << std::endl;
		return ;
	}
	id = std::atoi(input.c_str());
	for (int i = 0; i < _count; i++) {
		if (i + 1 == id) {
			_contacts[i].printContact();
			std::cout << std::endl;
			return ;
		}
	}
	std::cout << "ID is not valid, please try again" << std::endl << std::endl;

	return ;
 }

bool	PhoneBook::_str_isnum( std::string str ) const {

	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return (false);
		}
	}

	return (true);
}

PhoneBook::~PhoneBook( void ) {

	return ;
}
