#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice: public AMateria {

	private:

	public:
		Ice( void );
		Ice( Ice const & src );
		virtual ~Ice( void );
		Ice const &		operator = ( Ice const & rhs );

		virtual Ice *		clone( void ) const;
		virtual void		use( ICharacter & target );
};

#endif
