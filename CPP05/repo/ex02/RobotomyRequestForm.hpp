#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP\

# include "Form.hpp"

class	RobotomyRequestForm: public Form {

	private:
		std::string		_target;

		RobotomyRequestForm(void);
		virtual void	run(void) const;

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm const &	operator = (RobotomyRequestForm const & rhs);
};

#endif
