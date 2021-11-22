#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {

	std::cout << "Cat was created" << std::endl;

	return ;
}

Cat::Cat( Cat const & src ) : Animal( src ) {

	std::cout << "Cat was copied, now it's CopyCat!" << std::endl;

	return ;
}

Cat const &	Cat::operator = ( Cat const & rhs ) {

	Animal::operator = ( rhs );

	return *this;
}

void	Cat::makeSound( void ) const {

	std::cout << "MEOW-MEOOWW ?" << std::endl;

	return ;
}

Cat::~Cat( void ) {

	std::cout << "Cat ran away..." << std::endl;

	return ;
}

/* ******************************* WRONG CAT ******************************** */

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" ) {

	std::cout << "WrongCat was created" << std::endl;

	return ;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal( src ) {

	return ;
}

WrongCat const &	WrongCat::operator = ( WrongCat const & rhs ) {

	WrongAnimal::operator = ( rhs );

	return *this;
}

void	WrongCat::makeSound( void ) const {

	std::cout << "WRONG MEOW-MEOOWW ?" << std::endl;

	return ;
}

WrongCat::~WrongCat( void ) {

	std::cout << "WrongCat ran away..." << std::endl;

	return ;
}
