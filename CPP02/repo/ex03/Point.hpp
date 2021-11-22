#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {

	public:
		Point( void );
		Point( float const a, float const b );
		Point( Point const & src );
		~Point( void );

		Point const &	operator = ( Point const & rhs );
		Fixed const &	getX( void ) const;
		Fixed const &	getY( void ) const;

	private:
		Fixed const	x;
		Fixed const	y;
		Fixed	i;
		Fixed	j;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif
