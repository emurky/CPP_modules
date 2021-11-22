#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class	Bureaucrat;

class	Form {

	private:
		std::string const	_name;
		int const			_sign_grade;
		int const			_exec_grade;
		bool				_signed;

	protected:
		Form(void);
		virtual void		run(void) const = 0;

	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const & src);
		virtual ~Form(void);
		Form const &	operator = (Form const & rhs);

		std::string			getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getIsSigned(void) const;

		void				beSigned(Bureaucrat const & bureaucrat);
		void				execute(Bureaucrat const & executor) const;

	class	GradeTooHighException:	public std::exception {
		public:
			virtual const char *	what() const throw();
	};

	class	GradeTooLowException:	public std::exception {
		public:
			virtual const char *	what() const throw();
	};
};

std::ostream &			operator << (std::ostream & out, Form const & form);

#endif
