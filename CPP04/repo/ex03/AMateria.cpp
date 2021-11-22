#include "AMateria.hpp"

AMateria::AMateria( void ) : _type( "default" ) {

	// std::cout << "Default AMateria was created" << std::endl;

	return ;
}

AMateria::AMateria( std::string const & type ) : _type( type ) {

	// std::cout	<< "AMateria was created with type \"" << _type << "\""
				// << std::endl;

	return ;
}

AMateria::AMateria( AMateria const & src ) {

	// std::cout << "AMateria was copied" << std::endl;
	*this = src;

	return ;
}

AMateria const &		AMateria::operator = ( AMateria const & rhs ) {

	if ( this != &rhs ) {
		this->_type = rhs._type;
	}

	return *this;
}

std::string const &		AMateria::getType() const {

	return this->_type;
}

void		AMateria::use( ICharacter & target ){

	(void)target;
	return ;
}

AMateria::~AMateria( void ) {

	// std::cout << "AMateria was destroyed" << std::endl;

	return ;
}
