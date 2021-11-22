#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class	Brain {

	public:
		Brain( void );
		Brain( std::string tp );
		Brain( Brain const & src );
		~Brain( void );
		Brain const &		operator = ( Brain const & rhs );

		static std::string	itoa( int i );
		std::string &		getIdea( void );
		void				printIdeas( void ) const;
		static int const	ideasNum = 100;

	private:
		std::string			ideas[ ideasNum ];
		std::string			type;
};

#endif
