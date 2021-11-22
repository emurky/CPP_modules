#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class	ShrubberyCreationForm: public Form {

	private:
		std::string		_target;

		ShrubberyCreationForm(void);
		virtual void	run(void) const;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm const &	operator = (ShrubberyCreationForm const & rhs);
};

#endif
