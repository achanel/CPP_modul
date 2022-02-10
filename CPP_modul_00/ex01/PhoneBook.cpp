#include "PhoneBook.hpp"

void	print_str(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << "." << "|";
	else if (str.length() < 10)
		std::cout << std::setw(10) << str << "|";
	else
		std::cout << str << "|";
}

void	Contact::clear_contact()
{
	if (!first_name.empty())
	{
		first_name.clear();
		last_name.clear();
		nickname.clear();
		phone_number.clear();
		darkest_secret.clear();
	}
}

void	Contact::add_info()
{
	std::cout << "\033[1;32m### Add FIRST NAME commands ###\033[0m" << std::endl;
	std::cin >> first_name;
	std::cout << "\033[1;32m### Add LAST NAME commands ###\033[0m" << std::endl;
	std::cin >> last_name;
	std::cout << "\033[1;32m### Add NICKNAME commands ###\033[0m" << std::endl;
	std::cin >> nickname;
	std::cout << "\033[1;32m### Add PHONE NUMBER commands ###\033[0m" << std::endl;
	std::cin >> phone_number;
	std::cout << "\033[1;32m### Add DARKEST SECRET commands ###\033[0m" << std::endl;
	std::cin >> darkest_secret;
}

void	Contact::print_full_info()
{
	std::cout << "FIRST NAME:     " << first_name << std::endl;
	std::cout << "LAST NAME:      " << last_name << std::endl;
	std::cout << "NICKNAME:       " << nickname << std::endl;
	std::cout << "PHONE NUMBER:   " << phone_number << std::endl;
	std::cout << "DARKEST SECRET: " << darkest_secret << std::endl;
}

void	Contact::print_contact(int i)
{
	if (!first_name.empty())
	{
		std::cout << std::setw(10) << (i + 1) << "|";
		print_str(first_name);
		print_str(last_name);
		print_str(nickname);
		std::cout << std::endl;
	}
}

void	PhoneBook::search_contact()
{
	std::string	buf;

	std::cout << "\033[1;33m     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\033[0m" << std::endl;
	for (int a = 0; a < 50; a++)
		std::cout << "-";
	std::cout << std::endl;
	for (int j = 0; j < 8; j++)
		array[j].print_contact(j);
	std::cout << "\033[1;32m### Enter contact index ###\033[0m" << std::endl << std::endl;
	std::cin >> buf;
	if (atoi(buf.c_str()) < 1 || atoi(buf.c_str()) > 8)
		std::cout << "\033[1;31m### ERROR: wrong index ###\033[0m" << std::endl << std::endl;
	else
		array[stoi(buf) - 1].print_full_info();
}

void	PhoneBook::add_contact(int *i)
{
	if (*i == 7)
		*i = 0;
	else
		(*i)++;
	array[*i].clear_contact();
	array[*i].add_info();

}

void	PhoneBook::start_info()
{
	std::cout << "\033[1;32m### Use ADD, SEARCH or EXIT commands ###\033[0m" << std::endl << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	buf;
	int			i;

	i = -1;
	phonebook.start_info();
	while (true)
	{
		std::cin >> buf;
		if (buf.compare("EXIT") == 0)
			exit(EXIT_SUCCESS);
		else if (buf.compare("ADD") == 0)
			phonebook.add_contact(&i);
		else if (buf.compare("SEARCH") == 0)
			phonebook.search_contact();
	}
}