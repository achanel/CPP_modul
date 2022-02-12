#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"
# include <cmath>

class Point
{
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(const float a, const float b);
    Point(const Point &copy);
    Point& operator= (const Point &point);
    ~Point();

    float   getX();
    float   getY();
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif