#include<bits/stdc++.h>
using namespace std;
class Point
{
public:
    Point() : x(0), y(0){

                    };
    Point(double ix, double iy) : x(ix), y(iy){

                                         };
    Point(const Point &p) : x(p.x), y(p.y){

                                    };
    double getx() const
    {

        return x;
    }
    double gety() const
    {
        return y;
    }
    void print() const
    {
        cout << x << " " << y << endl;
    }
    bool operator==(const Point &p)
    {
        return (x == p.x) && (y == p.y);
    }
    bool operator=(const Point &p)
    {
        x = p.x;
        y = p.x;
        return true;
    }

private:
    double x;
    double y;
};