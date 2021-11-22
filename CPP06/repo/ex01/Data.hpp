#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <iomanip>

typedef struct	s_data {

	std::string	login;
	std::string	name;
	int			age;
}				Data;

uintptr_t	serialize(Data * ptr);
Data *		deserialize(uintptr_t raw);

#endif
