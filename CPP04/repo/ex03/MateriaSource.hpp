#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource: public IMateriaSource {

	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const & src );
		virtual ~MateriaSource( void );
		MateriaSource const &	operator = ( MateriaSource const & rhs );

		virtual void		learnMateria( AMateria * m );
		virtual AMateria *	createMateria( std::string const & type );
		static int const	maxM = 4;

	private:
		int			_countM;
		AMateria *	_inventory[ maxM ];
};

#endif
