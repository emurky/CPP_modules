#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixed( 0 ) {

	std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed( int const value ) : _fixed( value << _bits ) {

	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed( float const value ) : _fixed( roundf(value * (1 << _bits)) ) {

	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed &		Fixed::operator = ( Fixed const & rhs ) {

	std::cout << "Assignation operator called" << std::endl;
	this->_fixed = rhs.getRawBits();

	return ( *this );
}

std::ostream &	operator << ( std::ostream & out, Fixed const & fixed ) {

	out << fixed.toFloat();

	return ( out );
}

float	Fixed::toFloat( void ) const {

	return ( (float)this->_fixed / (1 << _bits) );
}

int		Fixed::toInt( void ) const {

	return ( this->_fixed >> this->_bits );
}

int		Fixed::getRawBits( void ) const {

	return ( this->_fixed );
}

void	Fixed::setRawBits( int const raw ) {

	this->_fixed = raw;

	return ;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

	return ;
}
