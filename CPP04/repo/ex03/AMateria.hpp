#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "Character.hpp"

class	ICharacter;

class	AMateria {

	protected:
		std::string		_type;

	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( AMateria const & src );
		virtual ~AMateria( void );
		AMateria const &		operator = ( AMateria const & rhs );

		std::string const &		getType( void ) const;

		virtual AMateria *	clone( void ) const = 0;
		virtual void		use( ICharacter & target );
};

#endif
