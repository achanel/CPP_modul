#include "Span.hpp"

# define COLOR "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    cout << "---------------------------------------\n";
    try
    {
        ::vector<int> tmp;
        srand(time(NULL));
        for (int i = 0; i < 10; ++i)
            tmp.push_back(rand() % 100);
        Span sp = Span(10);
        sp.addNumber(tmp.begin(), tmp.end());
        for (int i = 0; i < 10; ++i)
            cout << sp.getArray()->at(i) << " ";
        cout << endl;
        cout << GREEN << "shortest: " << sp.shortestSpan() << COLOR << endl;
        cout << GREEN << "longest: " << sp.longestSpan() << COLOR << endl;
    }
    catch(const exception &e)
    {
        std::cerr << e.what() << '\n';
    }
	cout << "---------------------------------------\n";
	try
	{
		::vector<int> tmp1;
		for (int i = 0; i < 10; ++i)
			tmp1.push_back(rand() % 100);
		Span sp1 = Span(10);
		sp1.addNumber(tmp1.begin(), tmp1.end() + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << COLOR << '\n';
	}
	cout << "---------------------------------------\n";
	try
	{
		Span sp2 = Span(2);
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.addNumber(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << COLOR << '\n';
	}
	cout << "---------------------------------------\n";
	try
	{
		Span sp3 = Span(1);
		sp3.addNumber(1);
		sp3.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << COLOR << '\n';
	}
    return 0;
}