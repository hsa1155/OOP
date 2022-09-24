#include<bits/stdc++.h>
using namespace std;
class Line
{
public:
    Line() : a(0), b(0), c(0){

                         };
    Line(double ia, double ib, double ic) : a(ia), b(ib), c(ic){

                                                          };
    Line(const Line &p) : a(p.a), b(p.b), c(p.c){

                                          };
    bool operator==(const Line &p)
    {
        return (a == p.a) && (b == p.b) && (c = p.c);
    }
    double geta() const
    {
        return a;
    }
    double getb() const
    {
        return b;
    }
    double getc() const
    {
        return c;
    }
    void print() const
    {
        cout << a << "x + " << b << "y";
        if (c >= 0)
        {
            cout << " + " << c << endl;
        }
        else
        {
            cout << " " << c << endl;
        }
    }

private:
    double a;
    double b;
    double c;
};