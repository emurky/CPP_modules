#include "Point.hpp"

Fixed	checkSign ( Point const pt, Point const a, Point const b )
{

	return		( pt.getX() - b.getX()) * (a.getY() - b.getY())
				- (a.getX() - b.getX()) * (pt.getY() - b.getY() );
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {

	Fixed	s1, s2, s3;

	s1 = checkSign( point, a, b );
	s2 = checkSign( point, b, c );
	s3 = checkSign( point, c, a );

	return ( ( s1 < 0 && s2 < 0 && s3 < 0 ) || ( s1 > 0 && s2 > 0 && s3 > 0 ) );
}
