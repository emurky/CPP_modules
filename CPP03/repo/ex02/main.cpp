#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void ) {

	ClapTrap	tony( "Tony" );
	ClapTrap	fred( "Fred" );
	ScavTrap	billy( "Billy" );
	FragTrap	phil( "Phil" );

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

	phil.attack( billy.getName() );
	billy.takeDamage( phil.getDamagePts() );
	billy.attack( phil.getName() );
	phil.takeDamage( billy.getDamagePts() );
	phil.highFivesGuys();
	std::cout << std::endl;

	std::cout	<< "========================================" << std::endl;

	return 0;
}
