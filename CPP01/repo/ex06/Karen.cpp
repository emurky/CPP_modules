#include "Karen.hpp"

Karen::Karen( void ) {

	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";

	return ;
}

void	Karen::complain( std::string level ) {

	int	i = 0;

	while ( _levels[i] != level && i < 4 ) {
		i++;
	}

	switch ( i ) {
		case 0:		debug();
		case 1:		info();
		case 2:		warning();
		case 3:		error();
					break ;
		default:	std::cout	<< "[ Probably complaining about "
								<< "insignificant problems ]" << std::endl
								<< std::endl;
	}

	return ;
}

void	Karen::debug( void ){

	std::cout << "[ " << _levels[0] << " ]" << std::endl;
	std::cout	<< "I love to get extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
				<< "I just love it!" << std::endl;
	std::cout << std::endl;

	return ;
}

void	Karen::info( void ) {

	std::cout << "[ " << _levels[1] << " ]" << std::endl;
	std::cout	<< "I cannot believe adding extra bacon cost more money. "
				<< "You don’t put enough! "
				<< "If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;

	return ;
}

void	Karen::warning( void ) {

	std::cout << "[ " << _levels[2] << " ]" << std::endl;
	std::cout	<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming here for years and "
				<< "you just started working here last month." << std::endl;
	std::cout << std::endl;

	return ;
}

void	Karen::error( void ) {

	std::cout << "[ " << _levels[3] << " ]" << std::endl;
	std::cout	<< "This is unacceptable, "
				<< "I want to speak to the manager now." << std::endl;
	std::cout << std::endl;

	return ;
}

Karen::~Karen( void ) {

	return ;
}
