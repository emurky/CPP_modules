#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class	Form;

class	Intern {

	typedef struct			s_forms {
		std::string			represents;
		Form *				(*form_ptrs)(std::string target);
	}						t_forms;

	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);
		Intern const &	operator = (Intern const & rhs);

		Form *				makeForm(std::string form, std::string target);
		static int const	fMax = 3;

	private:
		t_forms				_forms[fMax];
		static Form *		createShrubbery(std::string target);
		static Form *		createRoboRequest(std::string target);
		static Form *		createPardon(std::string target);
};

#endif
