#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Span
{
private:
    unsigned int    _N;
    ::vector<int>   *array;
public:
    Span(unsigned int N);
    Span(const Span &copy);
    Span const &operator=(const Span &other);
    ~Span();

    void    addNumber(int number);
    int     shortestSpan();
    int     longestSpan();
    ::vector<int>     *getArray() const;

    class SpanIsFull : public ::exception { virtual const char *what() const throw(); };
    class SpanIsShort : public ::exception { virtual const char *what() const throw(); };

    void    addNumber(::vector<int>::iterator start, ::vector<int>::iterator end);
};

std::ostream &operator<<(std::ostream &out, const Span &sp);

#endif