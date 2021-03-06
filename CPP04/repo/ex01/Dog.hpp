#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal {

	public:
		Dog( void );
		Dog( Dog const & src );
		virtual ~Dog( void );
		Dog const &	operator = ( Dog const & rhs );

		virtual void	makeSound( void ) const;
		void			printIdea( void ) const;

	private:
		Brain *		brain;
};

#endif
