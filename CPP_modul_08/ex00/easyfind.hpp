#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
typename T::iterator    easyfind(T &container, int n)
{
    vector<int>::iterator   iter;
    iter = find(container.begin(), container.end(), n);
    if (iter != container.end())
        return iter;
    throw exception();
}

#endif