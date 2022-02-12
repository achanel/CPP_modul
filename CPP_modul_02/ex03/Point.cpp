#include "Point.hpp"

Point::Point(void) : x(Fixed()), y(Fixed())
{
}

Point::Point(const float a, const float b) : x(a), y(b)
{
}

Point::Point(const Point &copy)
{
    const_cast<Fixed&>(x) = copy.x;
    const_cast<Fixed&>(y) = copy.y;
}

Point& Point::operator= (const Point &point)
{
    const_cast<Fixed&>(x) = point.x;
    const_cast<Fixed&>(y) = point.y;

    return *this;   
}

float   Point::getX(void)
{
    return (x.toFloat());
}

float   Point::getY(void)
{
    return (y.toFloat());
}

Point::~Point(void)
{
}