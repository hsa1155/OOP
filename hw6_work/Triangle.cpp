#include<iostream>
#include<string>
#include"Shape.h"
#include"Triangle.h"
using namespace std;

Triangle::Triangle(const string& str,int h,int b):Shape(str),height(h),base(b)
{
    cout<<"generate a Triangle"<<endl;

};

void Triangle::print()
{
    Shape::print();
    cout<<"Triangle:height="<<height<<" base="<<base<<" area="<<get_area()<<endl;
};
double Triangle::get_area()
{
    return (double)height*(double)base/2.0;
}
Triangle::~Triangle()
{
    cout<<"destroy a Triangle"<<endl;
}