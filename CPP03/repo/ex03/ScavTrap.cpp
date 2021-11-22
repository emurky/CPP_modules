#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {

	_hitpoints = _scav_hitpoints = 100;
	_energy_pts = _scav_energy_pts = 50;
	_attack_dmg = _scav_attack_dmg = 20;

	_className = "ScavTrap";
	std::cout	<< "ScavTrap default constructor was called" << std::endl;

	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {

	_hitpoints = _scav_hitpoints = 100;
	_energy_pts = _scav_energy_pts = 50;
	_attack_dmg = _scav_attack_dmg = 20;

	_className = "ScavTrap";
	std::cout	<< "ScavTrap parametrized constructor was called for "
				<< this->_name << std::endl;

	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap( src ) {

	_name = src._name;
	std::cout	<< "ScavTrap copy constructor was called for "
				<< this->_name << std::endl;

	return ;
}

ScavTrap const &	ScavTrap::operator = ( ScavTrap const & rhs ) {

	ClapTrap::operator = ( rhs );

	return *this;
}

void	ScavTrap::attack( std::string const & target ) {

	if ( _attack_dmg <= _hitpoints ) {
		_hitpoints -= _attack_dmg;
		std::cout	<< _className << " " << _name << " CRASHES " << target
					<< ", causing " << _attack_dmg << " points of DAAAMAAAGE!"
					<< std::endl;
	}
	else {
		std::cout	<< _className << " " << _name
					<< " doesn't have enough hitpoints "
					<< "to HIIIIT..." << std::endl;
	}

	return ;
}

void	ScavTrap::guardGate( void ){

	std::cout	<< _className << " " << _name
				<< " has entered in Gate keeper mode!"
				<< std::endl;

	return ;
}

ScavTrap::~ScavTrap( void ) {

	std::cout	<< "ScavTrap destructor was called for "<< this->_name
				<< std::endl;
	this->printStatus( "ScavTrap" );

	return ;
}
