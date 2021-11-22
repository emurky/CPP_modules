#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {

	public:
		Dog( void );
		Dog( Dog const & src );
		virtual ~Dog( void );
		Dog const &	operator = ( Dog const & rhs );

		virtual void	makeSound( void ) const;
};

/* ******************************* WRONG DOG ******************************** */

class WrongDog: public WrongAnimal {

	public:
		WrongDog( void );
		WrongDog( WrongDog const & src );
		~WrongDog( void );					//not virtual anymore
		WrongDog const &	operator = ( WrongDog const & rhs );

		void	makeSound( void ) const;	//not virtual anymore
};

#endif
