#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {

	std::cout << "Dog was created" << std::endl;

	return ;
}

Dog::Dog( Dog const & src ) : Animal( src ) {

	std::cout << "Dog was cloned" << std::endl;

	return ;
}

Dog const &	Dog::operator = ( Dog const & rhs ) {

	Animal::operator = ( rhs );

	return *this;
}

void	Dog::makeSound( void ) const {

	std::cout << "WUF WWWUUUFF !" << std::endl;

	return ;
}

Dog::~Dog( void ) {

	std::cout << "Dog ran away..." << std::endl;

	return ;
}

/* ******************************* WRONG DOG ******************************** */

WrongDog::WrongDog( void ) : WrongAnimal( "WrongDog" ) {

	std::cout << "WrongDog was created" << std::endl;

	return ;
}

WrongDog::WrongDog( WrongDog const & src ) : WrongAnimal( src ) {

	return ;
}

WrongDog const &	WrongDog::operator = ( WrongDog const & rhs ) {

	WrongAnimal::operator = ( rhs );

	return *this;
}

void	WrongDog::makeSound( void ) const {

	std::cout << "WRONG WUF WWWUUUFF !" << std::endl;

	return ;
}

WrongDog::~WrongDog( void ) {

	std::cout << "WrongDog ran away..." << std::endl;

	return ;
}
