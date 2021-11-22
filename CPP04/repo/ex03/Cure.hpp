#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure: public AMateria {

	private:

	public:
		Cure( void );
		Cure( Cure const & src );
		virtual ~Cure( void );
		Cure const &		operator = ( Cure const & rhs );

		virtual Cure *		clone( void ) const;
		virtual void		use( ICharacter & target );
};

#endif
