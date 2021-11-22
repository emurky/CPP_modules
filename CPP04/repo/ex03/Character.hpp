#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character: public ICharacter {

	public:
		Character( void );
		Character( std::string name );
		Character( Character const & src );
		virtual ~Character( void );
		Character const &	operator = ( Character const & rhs );

		virtual std::string const &		getName( void ) const;
		virtual void		equip( AMateria * m );
		virtual void		unequip( int idx );
		virtual void		use( int idx, ICharacter & target );
		static int const	maxM = 4;

	private:
		std::string	_name;
		int			_countM;
		AMateria *	_inventory[ maxM ];

};

#endif
