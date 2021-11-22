#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class	Fixed {

	public:
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed &	operator = ( Fixed const & rhs );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixed;
		static int const	_bits = 8;
};

std::ostream &	operator << ( std::ostream & out, Fixed const & fixed );

#endif
