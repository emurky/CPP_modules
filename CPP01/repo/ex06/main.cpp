#include "Karen.hpp"

int	main( int argc, char **argv ) {

	std::string	level;
	Karen		Karen;

	switch ( argc ) {
		case 2:		level = argv[1];
					Karen.complain(level);
					break ;
		default:	std::cout	<< "Karen complains about your arguments..."
								<< std::endl;
					return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
