#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void	print_error(std::string str) {

	std::cout << "Error: " << str << std::endl;
}

bool	error_checking
		(std::string & s1, std::string & s2, std::ifstream & file) {

	if (s1.empty() || s2.empty()) {
		print_error("String arguments should not be empty");
		return (false);
	}
	if (file.bad() || file.fail()) {
		print_error("Something is wrong with a file");
		return (false);
	}

	return (true);
}

void	outfile_name_handle(std::string & name) {

	int		begin;

	begin = name.rfind('/') + 1;
	name.erase(0, begin);
	name.append(".replace");
}

void	replace(std::ifstream & infile, std::ofstream & outfile,
				std::string & s1, std::string & s2) {

	std::stringstream	ss;
	std::string			buffer;
	int					begin_pos;
	int					shift;

	ss << infile.rdbuf();
	buffer = ss.str();

	if (s1.compare(s2)) {
		begin_pos = buffer.find(s1);
		while (!buffer.empty() && begin_pos != -1) {

			outfile << buffer.substr(0, begin_pos) << s2;
			shift = begin_pos + s1.length();
			buffer.erase(0, shift);
			begin_pos = buffer.find(s1);
		}
	}
	outfile << buffer;
}

int	main(int argc, char **argv) {

	if (argc != 4) {
		print_error("Wrong number of arguments");
		return (EXIT_FAILURE);
	}

	std::string			s1(argv[2]);
	std::string			s2(argv[3]);
	std::string			ofs_name(argv[1]);
	std::ifstream		infile(argv[1]);

	if (!error_checking(s1, s2, infile)) {
		return (EXIT_FAILURE);
	}

	outfile_name_handle(ofs_name);
	std::ofstream		outfile(ofs_name);
	if (outfile.bad() || outfile.fail()) {
		print_error("Cannot write to outfile");
		return (EXIT_FAILURE);
	}

	replace(infile, outfile, s1, s2);

	infile.close();
	outfile.close();

	return (EXIT_SUCCESS);
}
