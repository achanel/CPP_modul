#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class Array
{
private:
    T               *array;
    unsigned int    _size;
public:
    Array() : array(), _size() {};
    Array(unsigned int n) : array(new T[n]()), _size(n) {};
    Array(const Array<T> &copy)
    {
        array = new T[copy._size];
        _size = copy._size;
        for (unsigned int i = 0; i < copy._size; ++i)
            array[i] = copy.array[i];
    };
    const Array &operator=(const Array<T> &other)
    {
        if (this == &other)
            return *this;
        delete [] array;
        _size = other._size;
        array = new T[_size];
        for (unsigned int i = 0; i < other._size; ++i)
            array[i] = other.array[i];
        return *this;
    };
    ~Array() { delete [] array; };

    T &operator[](unsigned int n)
    {
        if (n > _size)
            throw std::out_of_range("index is out of bounds\n");
        return array[n];
    }
    unsigned int size(void) const { return _size; };
};

#endif