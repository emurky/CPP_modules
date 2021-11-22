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

		bool	operator > ( Fixed const & rhs ) const;
		bool	operator < ( Fixed const & rhs ) const;
		bool	operator >= ( Fixed const & rhs ) const;
		bool	operator <= ( Fixed const & rhs ) const;
		bool	operator == ( Fixed const & rhs ) const;
		bool	operator != ( Fixed const & rhs ) const;

		Fixed const		operator + ( Fixed const & rhs ) const;
		Fixed const		operator - ( Fixed const & rhs ) const;
		Fixed const		operator * ( Fixed const & rhs ) const;
		Fixed const		operator / ( Fixed const & rhs ) const;

		Fixed &			operator ++ ( void );
		Fixed			operator ++ ( int );
		Fixed &			operator -- ( void );
		Fixed			operator -- ( int );

		static Fixed &			min( Fixed & a, Fixed & b );
		static Fixed const &	min( Fixed const & a, Fixed const & b );
		static Fixed &			max( Fixed & a, Fixed & b );
		static Fixed const &	max( Fixed const & a, Fixed const & b );

	private:
		int					_fixed;
		static int const	_bits = 8;
};

std::ostream &	operator << ( std::ostream & out, Fixed const & fixed );

#endif
