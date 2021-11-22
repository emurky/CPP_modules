#include <iostream>
#include <iomanip>

int		main( void ) {

	std::string		brain = "HI THIS IS BRAIN";
	std::string *	stringPTR = &brain;
	std::string &	stringREF = brain;

	std::cout << std::setw(37) << "Address of a brain is "
													<< &brain << std::endl;
	std::cout << std::setw(37) << "Address of a brain by a pointer is "
													<< stringPTR << std::endl;
	std::cout << std::setw(37) << "Address of a brain by a reference is "
													<< &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "String displayed by a pointer: " << *stringPTR << std::endl;
	std::cout << "String displayed by a reference: " << stringREF << std::endl;

	return (0);
}
