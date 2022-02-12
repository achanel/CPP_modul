#include "Point.hpp"

int main( void ) {
    const Point a(0, 0);
    const Point b(10, 30);
    const Point c(20, 0);

    Point   *points = new Point[10];

    points[0] = Point(0, 0);
    points[1] = Point(10, 0);
    points[2] = Point(0, 10);
    points[3] = Point(5, 5);
    points[4] = Point(15, 5);
    points[5] = Point(5, 15);
    points[6] = Point(10, 30);
    points[7] = Point(5, 25);
    points[8] = Point(1, 1);
    points[9] = Point(20, 20);

    for (int i = 0; i < 10; i++)
    {
        std::cout << "point (" << points[i].getX() << ", " << points[i].getY() << ") is ";
        if (bsp(a, b, c, points[i]))
            std::cout << "inside the triangle\n";
        else
            std::cout << "outside the triangle\n";
    }
    delete [] points;
    return 0;
}