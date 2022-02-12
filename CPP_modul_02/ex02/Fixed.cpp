#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
    // std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int integer) : fixedPoint(integer << bit)
{
    // std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floatPoint) : fixedPoint(roundf(floatPoint * (1 << bit)))
{
    // std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &fixed) : fixedPoint(fixed.fixedPoint)
{
    // std::cout << "Copy constructor called\n";
}

Fixed   &Fixed::operator=(const Fixed& fixed)
{
    // std::cout << "Copy assignment operator called\n";
    fixedPoint = fixed.getRawBits();
    return *this;
}

bool    Fixed::operator==(const Fixed &fixed)
{
    return (this->getRawBits() == fixed.getRawBits());
}

bool    Fixed::operator!=(const Fixed &fixed)
{
    return (!(this->getRawBits() == fixed.getRawBits()));
}

bool    Fixed::operator>= (const Fixed &fixed)
{
    return (this->getRawBits() >= fixed.getRawBits());
}

bool    Fixed::operator<= (const Fixed &fixed)
{
    return (this->getRawBits() <= fixed.getRawBits());
}

bool    Fixed::operator> (const Fixed &fixed) const
{
    return (this->getRawBits() > fixed.getRawBits());
}

bool    Fixed::operator< (const Fixed &fixed) const
{
    return (this->getRawBits() < fixed.getRawBits());
}

Fixed   Fixed::operator+ (const Fixed &fixed)
{
    Fixed   tmp;

    tmp.setRawBits(this->getRawBits() + fixed.getRawBits());
    return (tmp);
}

Fixed   Fixed::operator- (const Fixed &fixed)
{
    Fixed   tmp;

    tmp.setRawBits(this->getRawBits() - fixed.getRawBits());
    return (tmp);
}

Fixed   Fixed::operator/ (const Fixed &fixed)
{
    Fixed   tmp;

    tmp = *this;
    return (tmp.toFloat() / fixed.toFloat());
}

Fixed   Fixed::operator* (const Fixed &fixed)
{
    Fixed   tmp;

    tmp = *this;
    return (tmp.toFloat() * fixed.toFloat());
}

Fixed&  Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed&  Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed   tmp(*this);

    this->fixedPoint++;
    return (tmp);
}

Fixed  Fixed::operator--(int)
{
    Fixed   tmp(*this);

    this->fixedPoint--;
    return (tmp);
}

Fixed &Fixed::min(Fixed &Fix1, Fixed &Fix2)
{
    return(Fix1 < Fix2 ? Fix1 : Fix2);
}

Fixed &Fixed::max(Fixed &Fix1, Fixed &Fix2)
{
    return(Fix1 > Fix2 ? Fix1 : Fix2);
}

const Fixed &Fixed::min(const Fixed &Fix1, const Fixed &Fix2)
{
    return(Fix1 < Fix2 ? Fix1 : Fix2);
}

const Fixed &Fixed::max(const Fixed &Fix1, const Fixed &Fix2)
{
    return(Fix1 > Fix2 ? Fix1 : Fix2);
}

float Fixed::toFloat( void ) const
{
    return ((float)this->fixedPoint / (float)(1 << this->bit));
}

int Fixed::toInt( void ) const
{
    return (fixedPoint >> bit);
}

int Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called\n";
    return fixedPoint;
}

void    Fixed::setRawBits(int raw)
{
    // std::cout << "setRawBits member function called\n";
    fixedPoint = raw;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";   
}