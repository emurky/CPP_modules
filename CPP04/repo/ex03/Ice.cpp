#include "Ice.hpp"

Ice::Ice( void ) : AMateria( "ice" ) {

	std::cout << "Ice was made" << std::endl;

	return ;
}

Ice::Ice( Ice const & src ) : AMateria( src ) {

	std::cout << "Ice was copied" << std::endl;

	return ;
}

Ice const &		Ice::operator = ( Ice const & rhs ) {

	AMateria::operator = ( rhs );

	return *this;
}

Ice *			Ice::clone( void ) const {

	Ice *	clone = new Ice( *this );

	return clone;
}

void			Ice::use( ICharacter & target ){

	std::cout	<< "* shoots an ice bolt at " << target.getName() << " *"
				<< std::endl;

	return ;
}

Ice::~Ice( void ) {

	std::cout << "Ice was destroyed" << std::endl;

	return ;
}
