#include "Karen.hpp"

Karen::Karen( void ) {

	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";

	_comments[0] = &Karen::debug;
	_comments[1] = &Karen::info;
	_comments[2] = &Karen::warning;
	_comments[3] = &Karen::error;

	return ;
}

void	Karen::complain( std::string level ) {

	int	i = 0;

	while ( _levels[i] != level && i < 4 ) {
		i++;
	}
	while ( i != 4 ) {
		std::cout << "[ " << _levels[i] << " ]" << std::endl;
		( this->*_comments[i] )();
		return ;
	}
	std::cout << "* LOUD AND UNBEARABLE KAREN NOISES *" << std::endl;

	return ;
}

void	Karen::debug( void ){

	std::cout	<< "I love to get extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I just love it!" << std::endl;

	return ;
}

void	Karen::info( void ) {

	std::cout	<< "I cannot believe adding extra bacon cost more money. "
				<< "You don’t put enough! "
				<< "If you did I would not have to ask for it!" << std::endl;

	return ;
}

void	Karen::warning( void ) {

	std::cout	<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming here for years and "
				<< "you just started working here last month." << std::endl;

	return ;
}

void	Karen::error( void ) {

	std::cout	<< "This is unacceptable, "
				<< "I want to speak to the manager now." << std::endl;

	return ;
}

Karen::~Karen( void ) {

	return ;
}
