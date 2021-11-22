#include "Brain.hpp"

Brain::Brain( void ) : type( "Animal" ) {

	std::cout << "Brain was created full of ideas!" << std::endl;
	for ( int i = 0; i < ideasNum; i++ ) {
		ideas[i] = "* IDEA " + Brain::itoa( i + 1 ) + " *";
	}
	// printIdeas();

	return ;
}

Brain::Brain( std::string tp ) : type( tp ) {

	type.append("'s");
	std::cout << type << " Brain was created full of ideas!" << std::endl;
	for ( int i = 0; i < ideasNum; i++ ) {
		ideas[i] = type + " * IDEA " + Brain::itoa( i + 1 ) + " *";
	}
	// printIdeas();
	std::cout << type << " first idea:" << std::endl << ideas[ 0 ] << std::endl;

	return ;
}

Brain::Brain( Brain const & src ) {

	std::cout << "Brain was copied" << std::endl;
	*this = src;

	return ;
}

Brain const &	Brain::operator = ( Brain const & rhs ) {

	for ( int i = 0; i < ideasNum; i++ ) {
		this->ideas[i] = rhs.ideas[i];
	}

	return *this;
}

void			Brain::printIdeas( void ) const {

	for ( int i = 0; i < ideasNum; i++ ) {
		std::cout << ideas[ i ] << std::endl;
	}

	return ;
}

std::string &	Brain::getIdea ( void ) {

	return ideas[ 0 ];
}

Brain::~Brain( void ) {

	std::cout << type << " ideas disappeared..." << std::endl;

	return ;
}

std::string		Brain::itoa( int i ) {

	std::stringstream	ss;
	std::string			itoa;

	ss << i;
	ss >> itoa;

	return itoa;
}
