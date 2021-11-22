#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class	PresidentialPardonForm: public Form {

	private:
		std::string		_target;

		PresidentialPardonForm(void);
		virtual void	run(void) const;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm const &	operator = (PresidentialPardonForm const & rhs);
};

#endif
