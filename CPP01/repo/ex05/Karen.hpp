#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>
# include <iostream>

class	Karen {

	public:
		Karen( void );
		~Karen( void );

		void	complain( std::string level );

	private:
		std::string	_levels[4];
		void	(Karen::*_comments[4])( void );

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif
