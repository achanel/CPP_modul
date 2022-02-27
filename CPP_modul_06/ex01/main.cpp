#include <iostream>
# define COLOR "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
using namespace std;

typedef struct s_data
{
	std::string	string;
	int			number;
}	Data;

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int	main(void)
{
	Data	A;
	Data	*B;

	A.string = "HELLO WORLD!";
	A.number = 42;

	cout << BLUE << B << COLOR << endl;
	cout << "Data str = " << GREEN << A.string << COLOR << "; Data number = " << YELLOW << A.number << COLOR << endl;
	cout << BLUE << &A << COLOR << endl;
	B = deserialize(serialize(&A));
	cout << "Data str = " << GREEN << A.string << COLOR << "; Data number = " << YELLOW << A.number << COLOR << endl;
	cout << BLUE << B << COLOR << endl;
}
