#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int                 fixedPoint;
    static const int    bit = 8;
public:
    Fixed();
    Fixed(const int integer);
    Fixed(const float floatPoint);
    Fixed(const Fixed &copy);
    Fixed& operator= (const Fixed &fixed);
    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits() const;
    void    setRawBits(int raw);
    ~Fixed();
};

#endif