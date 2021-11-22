#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) :
	_name( "none" ),
	_hitpoints( 10 ),
	_energy_pts( 10 ),
	_attack_dmg( 0 ) {

	std::cout	<< "ClapTrap default constructor was called" << std::endl;

	return ;
}

ClapTrap::ClapTrap( std::string name ) :
	_name( name ),
	_hitpoints( 10 ),
	_energy_pts( 10 ),
	_attack_dmg( 0 ) {

	std::cout	<< "ClapTrap parametrized constructor was called for "
				<< this->_name << std::endl;

	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

	*this = src;

	std::cout	<< "ClapTrap copy constructor was called for " << this->_name
				<< std::endl;

	return ;
}

ClapTrap const &	ClapTrap::operator = ( ClapTrap const & rhs ) {

	this->_name = rhs._name;
	this->_hitpoints = rhs._hitpoints;
	this->_energy_pts = rhs._energy_pts;
	this->_attack_dmg = rhs._attack_dmg;

	return *this;
}

void	ClapTrap::printStatus( void ) const {

	std::cout	<< "ClapTrap status:" << std::endl
				<< std::setw( 15 ) << std::left
				<< "Name: " << _name << std::endl
				<< std::setw( 15 ) << std::left
				<< "Hitpoints: " << _hitpoints << std::endl
				<< std::setw( 15 ) << std::left
				<< "Energy points: " << _energy_pts << std::endl
				<< std::setw( 15 ) << std::left
				<< "Attack damage: " << _attack_dmg << std::endl
				<< std::endl;

	return ;
}

void	ClapTrap::attack( std::string const & target ) {

	if ( _attack_dmg <= _hitpoints ) {
		_hitpoints -= _attack_dmg;
		std::cout	<< "ClapTrap " << _name << " attacks " << target
					<< " causing " << _attack_dmg << " points of damage!"
					<< std::endl;
	}
	else {
		std::cout	<< "ClapTrap " << _name << " doesn't have enough hitpoints "
					<< "to attack..." << std::endl;
	}

	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	if ( _energy_pts > amount ) {
		_energy_pts -= amount;
		std::cout	<< "ClapTrap " << _name << " takes " << amount
					<< " points of damage!" << std::endl;
	}
	else {
		_energy_pts = 0;
		std::cout	<< "ClapTrap " << _name << " takes damage "
					<< "and " << _name << " has no energy points left..."
					<< std::endl;
	}

	return ;
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	_energy_pts += amount;
	std::cout	<< "ClapTrap " << _name << " gains " << amount
				<< " energy points!" << std::endl;

	return ;
}

std::string		ClapTrap::getName( void ) const {

	return _name;
}

unsigned int	ClapTrap::getDamagePts( void ) const {

	return _attack_dmg;
}

void			ClapTrap::setName( std::string name ) {

	this->_name = name;
	return ;
}

void			ClapTrap::setDamagePts( unsigned int damage ) {

	this->_attack_dmg = damage;
	return ;
}

ClapTrap::~ClapTrap( void ) {

	std::cout	<< "ClapTrap destructor was called for "<< this->_name
				<< std::endl;
	this->printStatus();

	return ;
}
