#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {

	_hitpoints = _frag_hitpoints = 100;
	_energy_pts = _frag_energy_pts = 100;
	_attack_dmg = _frag_attack_dmg = 30;

	_className = "FragTrap";
	std::cout	<< "FragTrap default constructor was called" << std::endl;

	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {

	_hitpoints = _frag_hitpoints = 100;
	_energy_pts = _frag_energy_pts = 100;
	_attack_dmg = _frag_attack_dmg = 30;

	_className = "FragTrap";
	std::cout	<< "FragTrap parametrized constructor was called for "
				<< this->_name << std::endl;

	return ;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap ( src ) {

	_name = src._name;
	std::cout	<< "FragTrap copy constructor was called for "
				<< this->_name << std::endl;

	return ;
}

FragTrap const &	FragTrap::operator = ( FragTrap const & rhs ) {

	ClapTrap::operator = ( rhs );

	return *this;
}

void	FragTrap::attack( std::string const & target ) {

	if ( _attack_dmg <= _hitpoints ) {
		_hitpoints -= _attack_dmg;
		std::cout	<< _className << " " << _name << " boinks " << target
					<< ", causing " << _attack_dmg << " points of dddomage!"
					<< std::endl;
	}
	else {
		std::cout	<< _className << " " << _name
					<< " doesn't have enough hitpoints "
					<< "to hit properly..." << std::endl;
	}

	return ;
}

void	FragTrap::highFivesGuys( void ) {

	std::cout	<< "*** A POSITIVE HIGH FIVES REQUEST FROM "
				<< _name << " ***" << std::endl;

	return ;
}

FragTrap::~FragTrap( void ) {

	std::cout	<< "FragTrap destructor was called for "<< this->_name
				<< std::endl;
	this->printStatus( "FragTrap" );

	return ;
}
