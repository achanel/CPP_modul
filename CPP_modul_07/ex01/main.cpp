#include "iter.hpp"

using namespace std;

template <typename T>
void print(T a)
{
    cout << a << " ";
}

int main(void)
{
    int aInt[] = {1, 2, 3, 4, 5, 6, 7};
    string aStr[] = {"one", "two", "three"};
    iter(aInt, 5,print);
    cout << endl;
    iter(aStr, 3, print);
    cout << endl;
    return 0;
}