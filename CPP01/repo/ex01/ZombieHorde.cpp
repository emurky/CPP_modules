#include "Zombie.hpp"

#include <sstream>

Zombie *	zombieHorde( int N, std::string name ) {

	Zombie *			Horde = new Zombie[ N ];
	std::string			index;
	std::stringstream	ss;

	for ( int i = 0; i < N; i++ ) {
		ss.clear();
		ss << i + 1;
		ss >> index;
		Horde[i].setName( name + " " + index );
		Horde[i].announce();
	}

	return (Horde);
}
