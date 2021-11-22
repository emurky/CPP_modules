#include "ScavTrap.hpp"

int	main( void ) {

	ClapTrap	tony( "Tony" );
	ClapTrap	fred( "Fred" );
	ScavTrap	billy( "Billy" );

	std::cout << std::endl;
	tony.setDamagePts( 6 );
	fred.setDamagePts( 10 );
	tony.attack( fred.getName() );
	fred.takeDamage( tony.getDamagePts() );
	fred.attack( tony.getName() );
	tony.takeDamage( fred.getDamagePts() );
	tony.attack( fred.getName() );
	fred.beRepaired( 10 );
	std::cout << std::endl;

	fred.addHitpoints( 20 );
	fred.attack( billy.getName() );
	billy.takeDamage( fred.getDamagePts() );
	billy.attack( fred.getName() );
	fred.takeDamage( billy.getDamagePts() );
	billy.beRepaired( 50 );
	billy.guardGate();
	std::cout << std::endl;

	ScavTrap *	biggy	= new ScavTrap();
	std::cout	<< "========================================" << std::endl;
	delete		biggy;

	return 0;
}
