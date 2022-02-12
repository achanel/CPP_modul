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

    Fixed&  operator= (const Fixed &fixed);
    bool    operator== (const Fixed &fixed);
    bool    operator!= (const Fixed &fixed);
    bool    operator>= (const Fixed &fixed);
    bool    operator<= (const Fixed &fixed);
    bool    operator> (const Fixed &fixed) const;
    bool    operator< (const Fixed &fixed) const;
    Fixed   operator+ (const Fixed &fixed);
    Fixed   operator- (const Fixed &fixed);
    Fixed   operator/ (const Fixed &fixed);
    Fixed   operator* (const Fixed &fixed);
    Fixed&  operator++();
    Fixed&  operator--();
    Fixed  operator++(int);
    Fixed  operator--(int);

    float   toFloat( void ) const;
    int     toInt( void ) const;
    int     getRawBits() const;
    void    setRawBits(int raw);
    
    static Fixed& min(Fixed &Fix1, Fixed &Fix2);
    static Fixed& max(Fixed &Fix1, Fixed &Fix2);
    static const Fixed& min(const Fixed &Fix1, const Fixed &Fix2);
    static const Fixed& max(const Fixed &Fix1, const Fixed &Fix2);
    ~Fixed();
};


#endif