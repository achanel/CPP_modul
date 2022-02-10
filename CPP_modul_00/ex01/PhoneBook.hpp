#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:

	void	add_info();
	void	print_contact(int i);
	void	print_full_info();
	void	clear_contact();
};

class PhoneBook
{
private:
	Contact	array[8];

public:

	void	start_info();
	void	add_contact(int *i);
	void	search_contact();
};

#endif