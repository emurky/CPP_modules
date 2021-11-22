#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>

int	main(void) {

	std::string		input;
	PhoneBook		phonebook;

	system("clear");
	while (true) {
		std::cout << "phonebook -> ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			phonebook.addContact();
		}
		else if (input == "SEARCH") {
			phonebook.searchContact();
		}
		else if (input == "EXIT") {
			return (0);
		}
	}

	return (0);
}
