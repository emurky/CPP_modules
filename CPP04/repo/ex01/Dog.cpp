#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {

	std::cout << "Dog was created" << std::endl;
	brain = new Brain( Animal::type );

	return ;
}

Dog::Dog( Dog const & src ) : Animal( src ) {

	std::cout << "Dog was cloned" << std::endl;
	this->brain = new Brain( this->type );
	*this->brain = *src.brain;

	return ;
}

Dog const &	Dog::operator = ( Dog const & rhs ) {

	if ( this != &rhs ) {
		delete this->brain;
		Animal::operator = ( rhs );
		this->brain = new Brain( this->type );
		*this->brain = *rhs.brain;
	}

	return *this;
}

void	Dog::makeSound( void ) const {

	std::cout << "WUF WWWUUUFF !" << std::endl;

	return ;
}

void	Dog::printIdea( void ) const {

	std::cout << brain->getIdea() << std::endl;

	return ;
}

Dog::~Dog( void ) {

	delete brain;
	std::cout << "Dog ran away..." << std::endl;

	return ;
}
