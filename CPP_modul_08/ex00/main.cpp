#include "easyfind.hpp"

# define COLOR "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"

int main(void)
{
    ::vector<int> vector;
    ::vector<int>::iterator vIter;
    int n = 2;
    cout << "n: " << n << endl;
	srand(time(NULL));
    for (int i = 0; i < 10; ++i)
        vector.push_back(rand() % 10);
    for (vIter = vector.begin(); vIter != vector.end(); ++vIter)
        cout << YELLOW << *vIter << COLOR << ' ';
    cout << endl;
    try
    {
        {
            vIter = easyfind(vector, n);
            cout << GREEN << "I found: " << n << COLOR << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Not found" << COLOR << '\n';
    }
    return 0;
}