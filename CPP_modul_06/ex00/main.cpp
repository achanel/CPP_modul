#include <iostream>
# define COLOR "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
using namespace std;

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "Bad Arguments!\n";
		return 1;
	}
	try
	{
		char c = static_cast<char>(stoi(av[1]));
		if (isprint(c))
			cout << GREEN << "char: '" << c << "'" << COLOR << endl;
		else
			cout << YELLOW << "char: Non displayable\n" << COLOR;
	}
	catch(const exception& e)
	{
		cout << RED << "impossible\n" << COLOR;
	}
	try
	{
		int i = static_cast<int>(stoi(av[1]));
		cout << GREEN << "int: " << i << COLOR << endl;
	}
	catch(const exception& e)
	{
		cout << RED << "impossible\n" << COLOR;
	}
	try
	{
		float f = static_cast<float>(stof(av[1]));
		cout.precision(1);
		cout << fixed << GREEN << "float: " << f << "f" << COLOR << endl;
	}
	catch (out_of_range &outOfRange)
	{
		cout << GREEN << "float: " << numeric_limits<float>::infinity() << "f" << COLOR << endl;
	}
	catch(const exception& e)
	{
		cout << RED << "impossible\n" << COLOR;
	}
	try
	{
		float d = static_cast<double>(stod(av[1]));
		cout.precision(1);
		cout << fixed << GREEN << "double: " << d << COLOR << endl;
	}
	catch (out_of_range &outOfRange)
	{
		cout << GREEN << "double: " << numeric_limits<double>::infinity() << COLOR << endl;
	}
	catch(const exception& e)
	{
		cout << RED << "impossible\n" << COLOR;
	}
	return 0;
}