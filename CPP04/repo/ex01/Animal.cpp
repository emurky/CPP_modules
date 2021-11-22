#include "Animal.hpp"

Animal::Animal( void ) : type( "Animal" ) {

	std::cout << "Animal was created, just an animal" << std::endl;

	return ;
}

Animal::Animal( std::string tp ) : type( tp ) {

	std::cout << "Animal was created, and it's a " << type << "!" << std::endl;

	return ;
}

Animal::Animal( Animal const & src ) {

	std::cout << "Animal was cloned!" << std::endl;
	*this = src;

	return ;
}

Animal const &	Animal::operator = ( Animal const & rhs ) {

	this->type = rhs.type;

	return *this;
}

std::string		Animal::getType( void ) const {

	return this->type;
}

void	Animal::makeSound( void ) const {

	std::cout << "* MAKES SOME ANIMAL NOISES *" << std::endl;

	return ;
}

Animal::~Animal( void ) {

	std::cout << "Animal ran away..." << std::endl;

	return ;
}
