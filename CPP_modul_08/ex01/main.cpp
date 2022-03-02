#include "Span.hpp"

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
        sp.addNumber(tmp.begin(), tmp.end() - 1);
        for (int i = 0; i < 10; ++i)
            cout << sp.getArray()->at(i) << " ";
        cout << endl;
        cout << "here\n";
        cout << "shortest: " << sp.shortestSpan() << endl;
        cout << "longest: " << sp.longestSpan() << endl;
    }
    catch(const exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}