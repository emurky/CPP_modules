#include "DiamondTrap.hpp"

int	main( void ) {

	ClapTrap		tony( "Tony" );
	ClapTrap		fred( "Fred" );
	ScavTrap		billy( "Billy" );
	FragTrap		phil( "Phil" );
	DiamondTrap		saf( "Saf" );

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

	billy.attack( saf.getName() );
	saf.takeDamage( billy.getDamagePts() );
	saf.beRepaired( 100 );
	saf.addHitpoints( 100 );
	saf.attack( tony.getName() );
	saf.attack( billy.getName() );
	saf.attack( phil.getName() );
	saf.attack( fred.getName() );
	saf.guardGate();
	saf.highFivesGuys();
	saf.whoAmI();
	std::cout << std::endl;

	std::cout	<< "========================================" << std::endl;

	return 0;
}
