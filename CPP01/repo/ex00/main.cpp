#include "Zombie.hpp"

int		main( void ) {

	Zombie		Gary("Gary");
	Zombie *	Marvin;

	Marvin = newZombie("Marvin");
	randomChump("Billy");
	Marvin->announce();

	delete Marvin;
	Gary.announce();

	return (0);
}
