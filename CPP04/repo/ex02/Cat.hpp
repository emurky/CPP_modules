#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal {

	public:
		Cat( void );
		Cat( Cat const & src );
		virtual ~Cat( void );
		Cat const &	operator = ( Cat const & rhs );

		virtual void	makeSound( void ) const;
		void			printIdea( void ) const;

	private:
		Brain *		brain;
};

#endif
