#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <sstream>

class PhoneBook
{
	private:
		Contact toto[8];

	public:
		PhoneBook(void);
		~PhoneBook();
		void add(int i);
		void search(void) const;
	
};

#endif