#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap {

	protected:
		unsigned int	_scav_hitpoints;
		unsigned int	_scav_energy_pts;
		unsigned int	_scav_attack_dmg;

	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		virtual ~ScavTrap( void );
		ScavTrap const &	operator = ( ScavTrap const & rhs );

		void	attack( std::string const & target );
		void	guardGate( void );
};

#endif
