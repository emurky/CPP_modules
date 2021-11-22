#include "Zombie.hpp"

Zombie::Zombie( void ) : _name( "Shaun" ) {

	return ;
}

Zombie::Zombie( std::string name ) : _name( name ) {

	return ;
}

void	Zombie::announce( void ) const {

	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName( std::string name ) {

	this->_name = name;
	return ;
}

Zombie::~Zombie( void ) {

	std::cout << this->_name << " the Zombie died" << std::endl;
	return ;
}
