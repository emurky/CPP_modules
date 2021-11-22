#include "Converter.hpp"

void	converter(std::string string) {

	Data	data;

	bzero(&data, sizeof(data));
	data.str = string;

	if (handlePseudoLiterals(data)) {
		return ;
	}
	try {
		parseString(data);
		switch (data.type) {
			case CHAR:		handleChar(data);
							break ;
			case INT:		handleInt(data);
							break ;
			case FLOAT:		handleFloat(data);
							break ;
			case DOUBLE:	handleDouble(data);
							break ;
		}
	}
	catch (std::exception & e) {
		data.charOverflow = true;
		data.intOverflow = true;
		data.floatOverflow = true;
		data.doubleOverflow = true;
		printData(data);
	}

	return ;
}

void	parseString(Data & data) {

	char	c;
	size_t	len = data.str.length();

	if (len == 1 && !isdigit(data.str[0])) {
		data.type = CHAR;
		return ;
	}

	c = data.str[0];
	if (!(isdigit(c) ||	(c == '+' && isdigit(data.str[1])) ||
						(c == '-' && isdigit(data.str[1])))) {
		throw ConverterException();
	}

	c = data.str[len - 1];
	if (!(isdigit(c) || (c == 'f' && isdigit(data.str[len - 2])))) {
		throw ConverterException();
	}

	for (size_t i = 1; i < len - 1; i++) {
		c = data.str[i];
		if (!(isdigit(c) || c == '.')) {
			throw ConverterException();
		}
		if (c == '.' && data.dot == false) {
			data.dot = true;
		}
		else if (c == '.' && data.dot == true) {
			throw ConverterException();
		}
	}

	if (data.dot == true) {
		data.type = DOUBLE;
		if (data.str[len - 1] == 'f') {
			data.type = FLOAT;
			data.str.erase(len - 1, len);
		}
		return ;
	}
	else if (data.str[len - 1] == 'f') {
		throw ConverterException();
	}

	data.type = INT;
}

void	handleChar(Data & data) {

	data.c = static_cast<char>(data.str[0]);
	data.i = static_cast<int>(data.c);
	data.f = static_cast<float>(data.c);
	data.d = static_cast<double>(data.c);

	printData(data);
}

void	handleInt(Data & data) {

	std::istringstream	intStream(data.str);

	intStream >> data.i;
	data.c = static_cast<char>(data.i);
	data.f = static_cast<float>(data.i);
	data.d = static_cast<double>(data.i);
	if (!(CHAR_MIN <= data.i && data.i <= CHAR_MAX)) {
		data.charOverflow = true;
	}
	if (intStream.fail()) {
		data.intOverflow = true;
		data.floatOverflow = true;
		data.doubleOverflow = true;
	}

	printData(data);
}

void	handleFloat(Data & data) {

	std::istringstream	floatStream(data.str);

	floatStream >> data.f;
	data.c = static_cast<char>(data.f);
	data.i = static_cast<int>(data.f);
	data.d = static_cast<double>(data.f);
	if (!(CHAR_MIN <= data.i && data.i <= CHAR_MAX)) {
		data.charOverflow = true;
	}
	if (!(INT_MIN <= static_cast<long>(data.f) &&
		static_cast<long>(data.f) <= INT_MAX)) {
		data.intOverflow = true;
	}
	if (floatStream.fail()) {
		data.intOverflow = true;
		data.floatOverflow = true;
		data.doubleOverflow = true;
	}

	printData(data);
}

void	handleDouble(Data & data) {

	std::istringstream	doubleStream(data.str);

	doubleStream >> data.d;
	data.c = static_cast<char>(data.d);
	data.i = static_cast<int>(data.d);
	data.f = static_cast<float>(data.d);
	if (!(CHAR_MIN <= data.i && data.i <= CHAR_MAX)) {
		data.charOverflow = true;
	}
	if (!(INT_MIN <= static_cast<long>(data.d) &&
		static_cast<long>(data.d) <= INT_MAX)) {
		data.intOverflow = true;
	}
	if (doubleStream.fail()) {
		data.intOverflow = true;
		data.floatOverflow = true;
		data.doubleOverflow = true;
	}

	printData(data);
}

bool	handlePseudoLiterals(Data & data) {

	if (data.str == "-inff" || data.str == "+inff" || data.str == "nanf" ||
		data.str == "-inf" || data.str == "+inf" || data.str == "nan") {

		if (data.str == "-inff" || data.str == "-inf") {
			data.pseudo = "-inf";
		}
		else if (data.str == "+inff" || data.str == "+inf") {
			data.pseudo = "+inf";
		}
		else if (data.str == "nanf" || data.str == "nan") {
			data.pseudo = "nan";
		}

		printData(data);

		return true;
	}

	return false;
}

void	printData(Data & data) {

	if (!data.pseudo.empty()) {
		std::cout	<< std::setw(8) << std::left
					<< "char:" << "impossible" << std::endl
					<< std::setw(8) << std::left
					<< "int:" << "impossible" << std::endl
					<< std::setw(8) << std::left
					<< "float:" << data.pseudo + "f" << std::endl
					<< std::setw(8) << std::left
					<< "double:" << data.pseudo << std::endl;
		return ;
	}
	std::cout	<< std::setw(8) << std::left << "char:";
	if (data.charOverflow) {
		std::cout	<< "impossible" << std::endl;
	}
	else if (!isprint(data.c)) {
		std::cout	<< "non displayable" << std::endl;
	}
	else {
		std::cout	<< "\'" << data.c << "\'" << std::endl;
	}

	std::cout	<< std::setw(8) << std::left << "int:";
	if (data.intOverflow) {
		std::cout	<< "impossible" << std::endl;
	}
	else {
		std::cout	<< data.i << std::endl;
	}

	std::cout	<< std::setw(8) << std::left << "float:";
	if (data.floatOverflow) {
		std::cout	<< "impossible" << std::endl;
	}
	else {
		std::cout	<< data.f << checkDot(data.f) << "f" << std::endl;
	}

	std::cout	<< std::setw(8) << std::left << "double:";
	if (data.doubleOverflow) {
		std::cout	<< "impossible" << std::endl;
	}
	else {
		std::cout	<< data.d << checkDot(data.d) << std::endl;
	}
}

std::string	checkDot (double d) {

	std::string			ret;
	std::stringstream	ss;

	ss << d;
	ss >> ret;
	for (size_t i = 0; i < ret.length(); i++) {
		if (ret[i] == '.' || ret[i] == '-' || ret[i] == 'n') {
			ret.clear();
			return ret;
		}
	}
	ret = ".0";

	return ret;
}

ConverterException::ConverterException() {}

ConverterException::ConverterException(std::string const & err) {

	_err = "Error: " + err;
};

const char *	ConverterException::what() const throw() {

	return const_cast<char const *>(_err.c_str());
}

ConverterException::~ConverterException() throw() {}
