#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>

class	ClapTrap {

	private:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energy_pts;
		unsigned int	_attack_dmg;

	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		~ClapTrap( void );
		ClapTrap( ClapTrap const & src );
		ClapTrap const &	operator = ( ClapTrap const & rhs );

		void	attack( std::string const & target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

		std::string		getName( void ) const;
		unsigned int	getDamagePts( void ) const;
		void			setName( std::string name );
		void			setDamagePts( unsigned int damage );

		void	printStatus( void ) const;
};

#endif
