#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixed( 0 ) {

	return ;
}

Fixed::Fixed( int const value ) : _fixed( value << _bits ) {

	return ;
}

Fixed::Fixed( float const value ) : _fixed( roundf(value * (1 << _bits)) ) {

	return ;
}

Fixed::Fixed( Fixed const & src ) {

	*this = src;

	return ;
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

	return ;
}

Fixed &			Fixed::min( Fixed & a, Fixed & b ) {

	return ( a < b ? a : b );
}

Fixed const &	Fixed::min( Fixed const & a, Fixed const & b ) {

	return ( a < b ? a : b );
}

Fixed &			Fixed::max( Fixed & a, Fixed & b ) {

	return ( a > b ? a : b );
}

Fixed const &	Fixed::max( Fixed const & a, Fixed const & b ) {

	return ( a > b ? a : b );
}

/* *************************** Overload operators *************************** */

Fixed &		Fixed::operator = ( Fixed const & rhs ) {

	this->_fixed = rhs.getRawBits();

	return ( *this );
}

std::ostream &	operator << ( std::ostream & out, Fixed const & fixed ) {

	out << fixed.toFloat();

	return ( out );
}

bool	Fixed::operator > ( Fixed const & rhs ) const {

	return ( this->_fixed > rhs.getRawBits() );
}

bool	Fixed::operator < ( Fixed const & rhs ) const {

	return ( this->_fixed < rhs.getRawBits() );
}

bool	Fixed::operator >= ( Fixed const & rhs ) const {

	return ( this->_fixed >= rhs.getRawBits() );
}

bool	Fixed::operator <= ( Fixed const & rhs ) const {

	return ( this->_fixed <= rhs.getRawBits() );
}

bool	Fixed::operator == ( Fixed const & rhs ) const {

	return ( this->_fixed == rhs.getRawBits() );
}

bool	Fixed::operator != ( Fixed const & rhs ) const {

	return ( this->_fixed != rhs.getRawBits() );
}

Fixed const		Fixed::operator + ( Fixed const & rhs ) const {

	Fixed	ret;
	ret.setRawBits( this->_fixed + rhs.getRawBits() );

	return ( ret );
}

Fixed const		Fixed::operator - ( Fixed const & rhs ) const {

	Fixed	ret;
	ret.setRawBits( this->_fixed - rhs.getRawBits() );

	return ( ret );
}

Fixed const		Fixed::operator * ( Fixed const & rhs ) const {

	Fixed	ret;
	ret.setRawBits( this->_fixed * rhs.getRawBits() >> this->_bits );

	return ( ret );
}

Fixed const		Fixed::operator / ( Fixed const & rhs ) const {

	Fixed	ret;
	ret.setRawBits( ( this->_fixed << this->_bits ) / rhs.getRawBits() );

	return ( ret );
}

Fixed &		Fixed::operator ++ ( void ) {

	this->_fixed++;

	return ( *this );
}

Fixed		Fixed::operator ++ ( int ) {

	Fixed	ret( *this );
	this->_fixed++;

	return ( ret );
}

Fixed &		Fixed::operator -- ( void ) {

	this->_fixed--;

	return ( *this );
}

Fixed		Fixed::operator -- ( int ) {

	Fixed	ret( *this );
	this->_fixed--;

	return ( ret );
}

/* ************************************************************************** */
