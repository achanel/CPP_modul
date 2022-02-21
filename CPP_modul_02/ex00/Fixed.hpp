#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int                 fixedPoint;
    static const int    bit = 8;
public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed& operator= (const Fixed &fixed);
    int		getRawBits() const;
    void    setRawBits(int raw);
    ~Fixed();
};


#endif