#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _countM( 0 ) {

	std::cout << "MateriaSource was created" << std::endl;
	for ( int i = 0; i < maxM; i++ ) {
		_inventory[ i ] = NULL;
	}

	return ;
}

MateriaSource::MateriaSource( MateriaSource const & src ) : _countM( 0 ) {

	*this = src;
	std::cout << "MateriaSource was copied" << std::endl;

	return ;
}

MateriaSource const &	MateriaSource::operator = ( MateriaSource const & rhs )
{
	if ( this != &rhs ) {
		if ( this->_countM ) {
			for ( int i = 0; i < this->_countM; i++ ) {
				delete _inventory[ i ];
			}
		}
		this->_countM = rhs._countM;
		for ( int i = 0; i < this->_countM; i++ ) {
			this->_inventory[ i ] = rhs._inventory[ i ]->clone() ;
		}
	}

	return *this;
}

void		MateriaSource::learnMateria( AMateria * m ) {

	if ( m ) {
		if ( _countM < maxM ) {
			_inventory[ _countM ] = m;
			std::cout	<< "MateriaSource was equipped in " << _countM
						<< " slot" << std::endl;
			_countM++;
		}
		else {
			for ( int i = 0; i < maxM; i++ ) {
				if ( _inventory[ i ] == NULL ) {
					_inventory[ i ] = m;
					std::cout	<< "MateriaSource was equipped in "
								<< i << " slot" << std::endl;
					return ;
				}
			}
			std::cout	<< "MateriaSource is full, "
						<< "please unequip any slot" << std::endl;
			delete m;
		}
	}
	else {
		std::cout << "Materia does not exist" << std::endl;
	}

	return ;
}

AMateria *	MateriaSource::createMateria( std::string const & type ) {

	AMateria *		materia;

	for ( int i = 0; i < _countM; i++ ) {
		if ( _inventory[ i ]->getType() == type ) {
			materia = _inventory[ i ]->clone();
			std::cout	<< "Here you go, " << type << " was created"
						<< std::endl;
			return materia;
		}
	}
	std::cout	<< "MateriaSource has not \"" << type << "\" materia"
				<< std::endl;

	return 0;
}

MateriaSource::~MateriaSource( void ) {

	for ( int i = 0; i < this->maxM; i++ ) {
		delete _inventory[ i ];
	}
	std::cout << "MateriaSource was destroyed" << std::endl;

	return ;
}
