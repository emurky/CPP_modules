#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap {

	private:

	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap( void );
		FragTrap const &	operator = ( FragTrap const & rhs );

		void	attack( std::string const & target );
		void	highFivesGuys( void );
};

# endif
