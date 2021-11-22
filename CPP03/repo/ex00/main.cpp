#include "ClapTrap.hpp"

int	main( void ) {

	ClapTrap	billy( "Billy" );
	ClapTrap	fred( "Fred" );
	ClapTrap	joey( fred );
	ClapTrap	anon;

	joey = billy;
	joey.setName( "Joey" );

	std::cout << std::endl;
	fred.setDamagePts( 6 );
	billy.setDamagePts( 10 );
	fred.attack( billy.getName() );
	billy.takeDamage( fred.getDamagePts() );
	billy.attack( fred.getName() );
	fred.takeDamage( billy.getDamagePts() );
	fred.attack( billy.getName() );
	billy.beRepaired( 10 );
	std::cout << std::endl;

	return 0;
}
