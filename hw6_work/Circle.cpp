#include<iostream>
#include<string>
#include"Shape.h"
#include"Circle.h"
using namespace std;

Circle::Circle(const string& str,int r):Shape(str),radius(r)
{
    cout<<"generate a Circle"<<endl;

};

void Circle::print()
{
    Shape::print();
    cout<<"Circle:radius="<<radius<<" area= "<<get_area()<<endl;
};
double Circle::get_area()
{
    return (double)radius*(double)radius*3.14159265359;
}
Circle::~Circle()
{
    cout<<"destroy a Circle"<<endl;
}