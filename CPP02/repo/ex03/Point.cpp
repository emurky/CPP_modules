#include "Point.hpp"

Point::Point( void ) : x( 0 ), y ( 0 ) {

	i = x;
	j = y;

	return ;
}

Point::Point( float const a, float const b ) : x( a ), y( b ) {

	i = x;
	j = y;

	return ;
}

Point::Point( Point const & src ) {

	*this = src;

	return ;
}

Point const &	Point::operator = ( Point const & rhs ) {

	this->i = rhs.getX();
	this->j = rhs.getY();

	return ( *this );
}

Fixed const &	Point::getX( void ) const {

	return ( this->i );
}

Fixed const &	Point::getY( void ) const {

	return ( this->j );
}

Point::~Point( void ) {

	return ;
}
