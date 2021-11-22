#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) :
	ClapTrap(), ScavTrap(), FragTrap(), _name( "none" )
{
	ClapTrap::_name.append( "_clap_name" );
	this->_hitpoints = FragTrap::_frag_hitpoints;
	this->_energy_pts = ScavTrap::_scav_energy_pts;
	this->_attack_dmg = FragTrap::_frag_attack_dmg;

	this->_className = "DiamondTrap";
	std::cout	<< "DiamondTrap default constructor was called" << std::endl;

	return ;
}

DiamondTrap::DiamondTrap( std::string name ) :
	ClapTrap( name ), ScavTrap( name ), FragTrap( name ), _name( name )
{
	ClapTrap::_name.append( "_clap_name" );
	this->_hitpoints = FragTrap::_frag_hitpoints;
	this->_energy_pts = ScavTrap::_scav_energy_pts;
	this->_attack_dmg = FragTrap::_frag_attack_dmg;

	_className = "DiamondTrap";
	std::cout	<< "DiamondTrap parametrized constructor was called for "
				<< this->_name << std::endl;

	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) :
	ClapTrap( src ), ScavTrap( src ), FragTrap( src )
{
	_name = src._name;
	std::cout	<< "DiamondTrap copy constructor was called for "
				<< this->_name << std::endl;

	return ;
}

DiamondTrap const &	DiamondTrap::operator = ( DiamondTrap const & rhs ) {

	ClapTrap::operator = ( rhs );

	return *this;
}

void	DiamondTrap::attack( std::string const & target ) {

	ScavTrap::attack( target );

	return ;
}

void	DiamondTrap::guardGate( void ) {

	ScavTrap::guardGate();

	return ;
}

void	DiamondTrap::highFivesGuys( void ) {

	FragTrap::highFivesGuys();

	return ;
}

void	DiamondTrap::whoAmI( void ) const {

	std::cout	<< "My name is " << _name << ", but in my heart I'll always "
				<< "be " << ClapTrap::_name << "..." << std::endl;

	return ;
}

DiamondTrap::~DiamondTrap( void ) {

	std::cout	<< "DiamondTrap destructor was called for "<< this->_name
				<< std::endl;
	this->printStatus( "DiamondTrap" );

	return ;
}
