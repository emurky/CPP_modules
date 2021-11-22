#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>

class	ClapTrap {

	protected:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energy_pts;
		unsigned int	_attack_dmg;
		std::string		_className;

	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		virtual	~ClapTrap( void );
		ClapTrap( ClapTrap const & src );
		ClapTrap const &	operator = ( ClapTrap const & rhs );

		virtual void	attack( std::string const & target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );

		std::string		getName( void ) const;
		unsigned int	getDamagePts( void ) const;
		void			setName( std::string name );
		void			setDamagePts( unsigned int damage );
		void			addHitpoints( unsigned int amount );

		void	printStatus( std::string className ) const;
};

#endif
