#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class MutantStack : public stack<T>
{
public:
    MutantStack() : stack<T>() {};
    MutantStack(const MutantStack<T> &copy) : stack<T>(copy) {};
    MutantStack const &operator=(const MutantStack<T> &other)
    {
        if (this == &other)
            return *this;
        stack<T>::operator=(other);
        return *this;
    };
    virtual ~MutantStack() {};

    typedef typename stack<T>::container_type::iterator iterator;
    typedef typename stack<T>::container_type::const_iterator   const_iterator;
    typedef typename stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename stack<T>::container_type::const_reverse_iterator   const_reverse_iterator;

    iterator begin() { return this->c.begin(); };
    const_iterator begin() const { return this->c.begin(); };

    iterator end() { return this->c.end(); };
    const_iterator end() const { return this->c.end(); };

    reverse_iterator rbegin() { return this->c.rbegin(); };
    const_reverse_iterator rbegin() const { return this->c.rbegin(); };

    reverse_iterator rend() { return this->c.rend(); };
    const_reverse_iterator rend() const { return this->c.rend(); };
};

#endif
