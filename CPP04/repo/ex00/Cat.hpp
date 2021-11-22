#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal {

	public:
		Cat( void );
		Cat( Cat const & src );
		virtual ~Cat( void );
		Cat const &	operator = ( Cat const & rhs );

		virtual void	makeSound( void ) const;
};

/* ******************************* WRONG CAT ******************************** */

class WrongCat: public WrongAnimal {

	public:
		WrongCat( void );
		WrongCat( WrongCat const & src );
		~WrongCat( void );					//not virtual anymore
		WrongCat const &	operator = ( WrongCat const & rhs );

		void	makeSound( void ) const;	//not virtual anymore
};

#endif
