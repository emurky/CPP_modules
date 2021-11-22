#include "Cure.hpp"

Cure::Cure( void ) : AMateria( "cure" ) {

	std::cout << "Cure was made" << std::endl;

	return ;
}

Cure::Cure( Cure const & src ) : AMateria( src ) {

	std::cout << "Cure was copied" << std::endl;

	return ;
}

Cure const &		Cure::operator = ( Cure const & rhs ) {

	AMateria::operator = ( rhs );

	return *this;
}

Cure *			Cure::clone( void ) const {

	Cure *	clone = new Cure( *this );

	return clone;
}

void			Cure::use( ICharacter & target ){

	std::cout	<< "* heals " << target.getName() << "’s wounds *" << std::endl;

	return ;
}

Cure::~Cure( void ) {

	std::cout << "Cure was destroyed" << std::endl;

	return ;
}
