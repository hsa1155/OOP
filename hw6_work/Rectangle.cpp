#include<iostream>
#include<string>
#include"Shape.h"
#include"Rectangle.h"
using namespace std;

Rectangle::Rectangle(const string& str,int h,int w):Shape(str),height(h),width(w)
{
    cout<<"generate a Rectangle"<<endl;

};

void Rectangle::print()
{
    Shape::print();
    cout<<"Rectangle:height="<<height<<" width="<<width<<" area="<<get_area()<<endl;
};
double Rectangle::get_area()
{
    return height*width;
}
Rectangle::~Rectangle()
{
    cout<<"destroy a rectangle"<<endl;
}