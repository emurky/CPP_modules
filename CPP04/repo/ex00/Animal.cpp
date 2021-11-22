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

/* ******************************* WRONG ANIMAL ***************************** */

WrongAnimal::WrongAnimal( void ) : type( "WrongAnimal" ) {

	std::cout << "WrongAnimal was created, just a WrongAnimal" << std::endl;

	return ;
}

WrongAnimal::WrongAnimal( std::string tp ) : type( tp ) {

	std::cout << "WrongAnimal was created, and it's a " << type << "!" << std::endl;

	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) {

	std::cout << "WrongAnimal was cloned!" << std::endl;
	*this = src;

	return ;
}

WrongAnimal const &	WrongAnimal::operator = ( WrongAnimal const & rhs ) {

	this->type = rhs.type;

	return *this;
}

std::string		WrongAnimal::getType( void ) const {

	return this->type;
}

void	WrongAnimal::makeSound( void ) const {

	std::cout << "* MAKES SOME WRONG ANIMAL NOISES *" << std::endl;

	return ;
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout << "WrongAnimal ran away..." << std::endl;

	return ;
}
