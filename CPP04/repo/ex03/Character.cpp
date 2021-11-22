#include "Character.hpp"

Character::Character( void ) : _name( "noname" ), _countM( 0 ) {

	std::cout << "Character was born" << std::endl;
	for ( int i = 0; i < maxM; i++ ) {
		_inventory[ i ] = NULL;
	}

	return ;
}

Character::Character( std::string name ) : _name( name ), _countM( 0 ) {

	std::cout << "Character named \"" << _name <<  "\" was born!" << std::endl;
		for ( int i = 0; i < maxM; i++ ) {
		_inventory[ i ] = NULL;
	}

	return ;
}

Character::Character( Character const & src ) {

	*this = src;
	std::cout << "Character was copied from " << _name << std::endl;

	return ;
}

Character const &	Character::operator = ( Character const & rhs ) {

	if ( this != &rhs ) {
		this->_name = rhs._name;
		if ( this->_countM ) {
			for ( int i = 0; i < this->maxM; i++ ) {
				delete _inventory[ i ];
			}
		}
		this->_countM = rhs._countM;
		for ( int i = 0; i < this->maxM; i++ ) {
			this->_inventory[ i ] = NULL;
			if ( rhs._inventory[ i ] ) {
				this->_inventory[ i ] = rhs._inventory[ i ]->clone();
			}
		}
	}

	return *this;
}

void		Character::equip( AMateria * m ) {

	if ( m ) {
		if ( _countM < maxM ) {
			_inventory[ _countM ] = m;
			std::cout	<< "Inventory was equipped in " << _countM << " slot"
						<< std::endl;
			_countM++;
		}
		else {
			for ( int i = 0; i < maxM; i++ ) {
				if ( _inventory[ i ] == NULL ) {
					_inventory[ i ] = m;
					std::cout	<< "Inventory was equipped in "
								<< i << " slot" << std::endl;
					return ;
				}
			}
			std::cout	<< "Inventory is full, "
						<< "please unequip any slot" << std::endl;
			delete m;
		}
	}
	else {
		std::cout << "Materia does not exist" << std::endl;
	}

	return ;
}

void		Character::unequip( int idx ) {

	if ( 0 <= idx && idx < maxM ) {
		if ( _inventory[ idx ] ) {
			_inventory[ idx ] = NULL;
			std::cout	<< "Inventory item with " << idx
						<< " index was uneqipped" << std::endl;
		}
		else {
			std::cout	<< "This slot does not exist in your inventory"
						<< std::endl;
		}
	}
	else {
		std::cout	<< "Invalid inventory index: must be between 0 and "
					<< maxM - 1 << " (including both)" << std::endl;
	}

	return ;
}

void		Character::use( int idx, ICharacter & target ) {

	if ( 0 <= idx && idx < maxM ) {
		if ( _inventory[ idx ] ) {
			_inventory[ idx ]->use( target );
		}
		else {
			std::cout	<< "Inventory item with " << idx
						<< " index is uneqipped" << std::endl;
		}
	}
	else {
		std::cout	<< "Invalid inventory index: must be between 0 and "
					<< maxM - 1 << " (including both)" << std::endl;
	}

	return ;
}

std::string const &		Character::getName( void ) const {

	return this->_name;
}

Character::~Character( void ) {

	for ( int i = 0; i < this->maxM; i++ ) {
		delete _inventory[ i ];
	}
	std::cout << "Character died..." << std::endl;

	return ;
}
