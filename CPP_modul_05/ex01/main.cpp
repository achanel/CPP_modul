#include "Form.hpp"

int main(void)
{
    Form    good("Good", 49, 97);
    std::cout << "-------------------------------------------\n";
    try
	{
		Form bad("Bad", 151, 20);
        std::cout << bad << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << YELLOW << e.what() << COLOR << std::endl;
	}
	std::cout << "-------------------------------------------\n";
    Bureaucrat  a("Fill", 150);
    Bureaucrat  b("John", 20);
    Form        form("Form1", 120, 100);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "-------------------------------------------\n";
    try
    {
        form.beSigned(a);
    }
    catch(const std::exception& e)
    {
        std::cerr << YELLOW << e.what() << COLOR << std::endl;
    }
    form.beSigned(b);
    std::cout << form << std::endl;
    std::cout << "-------------------------------------------\n";
    return 0;
}