#include "Data.hpp"

int	main(void) {

	Data *		data = new Data;
	uintptr_t	raw;
	Data *		deraw;

	data->login = "emurky";
	data->name = "Safar";
	data->age = 27;

	raw = serialize(data);
	deraw = deserialize(raw);

	std::cout	<< std::setw(34) << std::left
				<< "Address of original data:" << data << std::endl
				<< "Address of deserialized and back: " << deraw << std::endl
				<< std::endl;

	std::cout	<< "login: " << deraw->login << std::endl
				<< "name:  " << deraw->name << std::endl
				<< "age:   " << deraw->age << std::endl;

	delete data;

	return 0;
}

uintptr_t	serialize(Data * ptr) {

	return reinterpret_cast<uintptr_t>(ptr);
}

Data *		deserialize(uintptr_t raw) {

	return reinterpret_cast<Data *>(raw);
}
