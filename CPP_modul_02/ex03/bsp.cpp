#include "Point.hpp"

float   dotProduct(Point p1, Point p2, Point p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool    bsp( Point const a, Point const b, Point const c, Point const point)
{
    float   d1, d2, d3;
    bool    neg;
    bool    pos;

    d1 = dotProduct(point, a, b);
    d2 = dotProduct(point, b, c);
    d3 = dotProduct(point, c, a);
    neg = d1 < 0 || d2 < 0 || d3 < 0;
    pos = d1 > 0 || d2 > 0 || d3 > 0;
    return !(neg && pos);
}