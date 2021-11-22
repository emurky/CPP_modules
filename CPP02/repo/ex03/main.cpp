#include "Point.hpp"
#include <iostream>

int		main( void ) {

	Point	a( 72.60, -2.17 );
	Point	b( 61.07, 63.8 );
	Point	c( 8.93, 28.98 );
	Point	point( 42.42, 21.21 );

	if ( bsp( a, b, c, point) ) {
		std::cout << "Point is IN a triangle" << std::endl;
	}
	else {
		std::cout << "Point is OUTSIDE of a triangle" << std::endl;
	}

	return (0);
}
