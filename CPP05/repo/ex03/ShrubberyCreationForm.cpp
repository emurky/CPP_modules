#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iomanip>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("Shrubbery Creation Form", 145, 137),
	_target(target) {

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	Form(src) {

	_target = src._target;

	return ;
}

ShrubberyCreationForm const &	ShrubberyCreationForm::operator = (ShrubberyCreationForm const & rhs) {

	Form::operator = (rhs);
	_target = rhs._target;

	return *this;
}

void	ShrubberyCreationForm::run(void) const {

	std::ofstream	outfile(_target + "_shrubbery");

	if (outfile.bad() || outfile.fail()) {
		std::cout	<< "Error occured while creating a new file" << std::endl;
		throw std::exception();
		return ;
	}

	outfile	<< std::setw(55) << std::left<< "            .        +          .      .          ." << std::endl
			<< std::setw(55) << std::left<< "     .            _        .                    ." << std::endl
			<< std::setw(55) << std::left<< "  ,        *     /;-._,-.____        ,-----.__" << std::endl
			<< std::setw(55) << std::left<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl
			<< std::setw(55) << std::left<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << "      .  - - -" << std::endl
			<< std::setw(55) << std::left<< "                      ,    `./  \\:. `.   )==-'  ." << "  *    -        -  -     --    -" << std::endl
			<< std::setw(55) << std::left<< "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << "    -                 -         -  -" << std::endl
			<< std::setw(55) << std::left<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << "   -                -" << std::endl
			<< std::setw(55) << std::left<< "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << "   -               -                --" << std::endl
			<< std::setw(55) << std::left<< "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << "   -          -            -              -" << std::endl
			<< std::setw(55) << std::left<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << "   -            '-,        -               -" << std::endl
			<< std::setw(55) << std::left<< "              \\:  `  X` _| _,\\/'   .-'" << "   -              'b      *" << std::endl
			<< std::setw(55) << std::left<< ".               \":._:`\\____  /:'  /      .           ." << "    -              '$    #-                --" << std::endl
			<< std::setw(55) << std::left<< "                    \\::.  :\\/:'  /              +" << "   -    -           $:   #:               -" << std::endl
			<< std::setw(55) << std::left<< "   .                 `.:.  /:'  }      ." << " --      -  --      *#  @):        -   - -" << std::endl
			<< std::setw(55) << std::left<< "           .           ):_(:;   \\           ." << "              -     :@,@):   ,-**:\'   -" << std::endl
			<< std::setw(55) << std::left<< "                      /:. _/ ,  |" << "  -      -,         :@@*: --**'      -   -" << std::endl
			<< std::setw(55) << std::left<< "             *     . (|::.     ,`       . *        ." << "           '#o-    -:(@'-@*\"'  -" << std::endl
			<< std::setw(55) << std::left<< "     .                |::.    {\\" << "   -  -       'bq,--:,@@*'   ,*      -  -" << std::endl
			<< std::setw(55) << std::left<< "                      |::.\\  \\ `." << "              ,p$q8,:@)'  -p*'      -" << std::endl
			<< std::setw(55) << std::left<< "                      |:::(\\    |" << "    .  -     '  - '@@Pp@@*'    -  -" << std::endl
			<< std::setw(55) << std::left<< "              O       |:::/{ }  |      .           (o" << "        -  - --    Y7'.'     -  -" << std::endl
			<< std::setw(55) << std::left<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << "                  :@):." << std::endl
			<< std::setw(55) << std::left<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << "                 .:@:'." << std::endl
			<< std::setw(55) << std::left<< "ss    ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~\"" << "               .::(@:.      " << std::endl
			<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	outfile.close();
	std::cout	<< "Beautiful shrubberies was created in " << _target
				<< std::endl;

	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

	return ;
}
