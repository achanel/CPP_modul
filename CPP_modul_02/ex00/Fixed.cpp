#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed) : fixedPoint(fixed.fixedPoint)
{
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called\n";
    fixedPoint = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return fixedPoint;
}

void    Fixed::setRawBits(int raw)
{
    std::cout << "setRawBits member function called\n";
    fixedPoint = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";   
}