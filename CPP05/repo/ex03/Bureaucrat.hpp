#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class	Form;

class	Bureaucrat {

	private:
		std::string const	_name;
		int 				_grade;

		Bureaucrat(void);

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		Bureaucrat const &	operator = (Bureaucrat const & rhs);

		std::string		getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);

		void			signForm(Form & form) const;
		void			executeForm(Form const & form);

	class	GradeTooHighException:	public std::exception {
		public:
			virtual const char *	what() const throw();
	};

	class	GradeTooLowException:	public std::exception {
		public:
			virtual const char *	what() const throw();
	};
};

std::ostream &		operator << (std::ostream & out, Bureaucrat const & bc);

#endif
