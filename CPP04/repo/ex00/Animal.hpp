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

/* ******************************* WRONG ANIMAL ***************************** */

class	WrongAnimal {

	protected:
		std::string		type;

	public:
		WrongAnimal( void );
		WrongAnimal( std::string tp );
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal( void );						//not virtual anymore
		WrongAnimal const &	operator = ( WrongAnimal const & rhs );

		std::string		getType( void ) const;
		void			makeSound( void ) const;	//not virtual anymore
};

#endif
