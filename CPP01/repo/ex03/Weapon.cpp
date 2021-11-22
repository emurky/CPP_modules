#include "Weapon.hpp"

Weapon::Weapon( void ) {

	return ;
}

Weapon::Weapon( std::string type ) : _type(type) {

	return ;
}

Weapon::~Weapon( void ) {

	return ;
}

std::string &		Weapon::getType( void ) {

	std::string &	typeRef = this->_type;

	return (typeRef);
}

void	Weapon::setType( std::string type ) {

	this->_type = type;

	return ;
}
