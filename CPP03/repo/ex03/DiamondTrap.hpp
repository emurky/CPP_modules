#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap {

	private:
		std::string	_name;

	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const & src );
		virtual ~DiamondTrap( void );

		DiamondTrap const &	operator = ( DiamondTrap const & rhs );
		void	attack( std::string const & target );

		void	guardGate( void );
		void	highFivesGuys( void );
		void	whoAmI( void ) const;
};

#endif
