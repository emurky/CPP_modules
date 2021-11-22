#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal {

	protected:
		std::string		type;

	public:
		Animal( void );
		Animal( std::string tp );
		Animal( Animal const & src );
		virtual ~Animal( void );
		Animal const &	operator = ( Animal const & rhs );

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
};

#endif
