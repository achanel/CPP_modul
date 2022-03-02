#include "Span.hpp"

Span::Span(unsigned int n) : _N(n)
{
    array = new ::vector<int>;
}

Span::Span(const Span &copy)
{
    array = new ::vector<int>;
    _N = copy._N;
    for (size_t i = 0; i < copy._N; ++i)
        array[i] = copy.array[i];
}

const Span &Span::operator=(const Span &other)
{
    if (this == &other)
        return *this;
    delete array;
    array = new ::vector<int>;
    _N = other._N;
    for (size_t i = 0; i < other._N; ++i)
        array[i] = other.array[i];
    return *this;
}

Span::~Span()
{
    delete array;
}

int Span::shortestSpan()
{
    int res = INT_MAX;
    int diff;
    if (array->size() < 2)
        throw SpanIsShort();
    for (size_t i = 0; i < array->size() - 1; ++i)
        diff = ::abs((*array)[i] - (*array)[i + 1]);
    if (diff < res)
        res = diff;
    return res;
}

int Span::longestSpan()
{
    if (array->size() < 2)
        throw SpanIsShort();
    int a = *max_element(array->begin(), array->end());
    int b = *min_element(array->begin(), array->end());
    return a - b;
}

::vector<int>     *Span::getArray() const
{
    return this->array;
}

void    Span::addNumber(int number)
{
    if (array->size() >= _N)
        throw SpanIsFull();
    array->push_back(number);
}

void    Span::addNumber(::vector<int>::iterator start, ::vector<int>::iterator end)
{
    size_t  dst = ::distance(start, end);
    if (dst > _N)
        throw ::out_of_range("Out of range!\n");
    array->insert(array->begin(), start, end);
}

const char *Span::SpanIsFull::what() const throw()
{
    return "Span is full!";
}

const char *Span::SpanIsShort::what() const throw()
{
    return "Span is too short!";
}

std::ostream &operator<<(std::ostream &out, const Span &sp)
{
	out << sp.getArray();
	return out;
}
