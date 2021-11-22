#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

const int	contNum = 8;

class	PhoneBook {

	public:
		PhoneBook( void );
		~PhoneBook( void );

		void		addContact( void );
		bool		printContacts( void ) const;
		void		searchContact( void ) const;

	private:
		Contact		_contacts[contNum];
		int			_count;

		bool		_str_isnum( std::string str ) const;
};

#endif
