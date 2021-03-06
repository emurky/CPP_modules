#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact {

	public:
		Contact( void );
		~Contact( void );

		void			print_formatted( std::string field ) const;
		void			printContactInLine( void ) const;
		void			printContact( void ) const;
		void			setContact( void );

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;
};

#endif
