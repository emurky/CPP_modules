#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap {

	protected:
		unsigned int	_frag_hitpoints;
		unsigned int	_frag_energy_pts;
		unsigned int	_frag_attack_dmg;

	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		virtual ~FragTrap( void );
		FragTrap const &	operator = ( FragTrap const & rhs );

		void	attack( std::string const & target );
		void	highFivesGuys( void );
};

# endif
