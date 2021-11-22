#include "Cat.hpp"
#include "Dog.hpp"

int	main( void ) {

	std::cout << std::endl << "========= NORMAL PART ==========" << std::endl;

	const Animal *	meta = new Animal();
	const Animal *	dog = new Dog();
	const Animal *	cat = new Cat();

	std::cout << std::endl;

	std::cout << meta->getType() << " - Animal's type" << std::endl;
	std::cout << dog->getType() << " - Animal's type" << std::endl;
	std::cout << cat->getType() << " - Animal's type" << std::endl;

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl << "========== WRONG PART ==========" << std::endl;

	const WrongAnimal *	wrong_meta = new WrongAnimal();
	const WrongAnimal *	wrong_dog = new WrongDog();
	const WrongAnimal *	wrong_cat = new WrongCat();
	const WrongCat *	wrong_true_cat = new WrongCat();

	std::cout << std::endl;

	std::cout << wrong_meta->getType() << " - WrongAnimal's type" << std::endl;
	std::cout << wrong_dog->getType() << " - WrongAnimal's type" << std::endl;
	std::cout << wrong_cat->getType() << " - WrongAnimal's type" << std::endl;
	std::cout << wrong_true_cat->getType() << " - WrongAnimal's type" << std::endl;

	wrong_meta->makeSound();
	wrong_dog->makeSound();
	wrong_cat->makeSound();
	wrong_true_cat->makeSound();

	std::cout << std::endl;

	delete wrong_meta;
	delete wrong_dog;
	delete wrong_cat;
	delete wrong_true_cat;

	return 0;
}
