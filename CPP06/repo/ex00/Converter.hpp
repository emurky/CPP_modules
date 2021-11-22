#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <cfloat>

typedef	int		t_type;

enum e_types	{CHAR, INT, FLOAT, DOUBLE};

struct			Data {

	t_type		type;
	std::string	str;
	std::string	pseudo;
	bool		dot;
	char		c;
	int			i;
	float		f;
	double		d;
	bool		charOverflow;
	bool		intOverflow;
	bool		floatOverflow;
	bool		doubleOverflow;
};

class			ConverterException: public std::exception {

	private:
		std::string	_err;

	public:
		ConverterException();
		ConverterException(std::string const & err);
		virtual ~ConverterException()	throw();
		virtual const char *	what() const throw();
};

void			converter(std::string string);
void			parseString(Data & data);
void			handleChar(Data & data);
void			handleInt(Data & data);
void			handleFloat(Data & data);
void			handleDouble(Data & data);
bool			handlePseudoLiterals(Data & data);
void			printData(Data & data);
std::string		checkDot (double d);

#endif
