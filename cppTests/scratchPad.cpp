#include <iostream>

using namespace std;

class Point
{
    double x,y;
public:
    Point(double p, double q)
    {
        x = p;
        y = q;
        return;
    }
};

class Disk
{
    Point center;
    double radius;
public:
    Disk(double x, double y, double r):center(Point(1,2)),radius(3)
    {
        return;
    }
};

int main()
{
    Point point(1,2);
    return 0;

}