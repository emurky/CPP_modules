#include "Cat.hpp"
#include "Dog.hpp"

static int const	animalsNum = 2;

int	main( void ) {

	std::cout << std::endl << "========== PART ONE ==========" << std::endl;

	Animal *	animals[ animalsNum ];
	// Animal		animal;	// would not compile

	for ( int i = 0; i < animalsNum; i++ ) {
		if ( i % 2 ) {
			animals[ i ] = new Dog;
		}
		else {
			animals[ i ] = new Cat;
		}
		std::cout << std::endl;
	}

	std::cout << "Cat sounds like: " ;
	animals[ 0 ]->makeSound();
	std::cout << std::endl;
	std::cout << "Dog sounds like: ";
	animals[ 1 ]->makeSound();
	std::cout << std::endl;

	for ( int j = 0; j < animalsNum; j++ ){
		delete animals[ j ];
		std::cout << std::endl;
	}

	std::cout << "========== PART TWO ==========" << std::endl;

	Cat *	cat = new Cat;
	std::cout << std::endl;

	Cat *	copyCat = new Cat( *cat );
	std::cout << std::endl;

	Cat *	sameCat = new Cat;
	*sameCat = *cat;

	std::cout << std::endl;
	delete cat;

	std::cout << std::endl;
	std::cout << "copyCat's idea:" << std::endl;
	copyCat->printIdea();

	std::cout << "sameCat's idea:" << std::endl;
	sameCat->printIdea();
	std::cout << std::endl;

	delete copyCat;
	delete sameCat;

	return 0;
}
