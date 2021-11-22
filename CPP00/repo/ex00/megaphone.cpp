#include <iostream>
#include <string>

std::string	str_toupper(std::string str) {

	std::string		upper_str = str;

	for (size_t i = 0; i < upper_str.length(); i++) {
		upper_str[i] = toupper(str[i]);
	}

	return (upper_str);
}

int	main( int argc, char **argv ) {

	std::string			string;
	std::string	const	noise ( "* LOUD AND UNBEARABLE FEEDBACK NOISE *" );

	if (argc == 1) {
		std::cout << noise << std::endl;
	}
	else {
		argv++;
		while (*argv) {
			string = str_toupper(*argv);
			std::cout << string;
			argv++;
		}
		std::cout << std::endl;
	}

	return (0);
}
