#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {

	std::cout << "Cat was created" << std::endl;
	brain = new Brain( Animal::type );

	return ;
}

Cat::Cat( Cat const & src ) : Animal( src ) {

	std::cout << "Cat was copied, now it's CopyCat!" << std::endl;
	this->brain = new Brain( this->type );
	*this->brain = *src.brain;

	return ;
}

Cat const &	Cat::operator = ( Cat const & rhs ) {

	if ( this != &rhs ) {
		delete this->brain;
		Animal::operator = ( rhs );
		this->brain = new Brain( this->type );
		*this->brain = *rhs.brain;
	}

	return *this;
}

void	Cat::makeSound( void ) const {

	std::cout << "MEOW-MEOOWW ?" << std::endl;

	return ;
}

void	Cat::printIdea( void ) const {

	std::cout << brain->getIdea() << std::endl;

	return ;
}

Cat::~Cat( void ) {

	delete brain;
	std::cout << "Cat ran away..." << std::endl;

	return ;
}
