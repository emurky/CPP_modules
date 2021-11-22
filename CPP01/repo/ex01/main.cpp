#include "Zombie.hpp"

int		main( void ) {

	Zombie		Gary( "Gary" );
	Zombie *	Horde;

	Gary.announce();
	Horde = zombieHorde( 21, "Shaun" );

	delete [] Horde;

	return (0);
}
