#include "Converter.hpp"

int	main(int argc, char **argv) {

	std::string		string;

	if (argc != 2) {
		std::cout	<< "Error: Wrong number of arguments (must be just one)"
					<< std::endl;
		return EXIT_FAILURE;
	}
	string = static_cast<std::string>(argv[1]);
	converter(string);

	return 0;
}
