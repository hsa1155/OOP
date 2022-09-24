#include<iostream>
#include<string>
#include"Shape.h"
using namespace std;

Shape::Shape(const string& str):color(str)
{
    cout<<"generate a shape"<<endl;
    cout<<"this color is "<<color<<endl;

};

void Shape::print()
{
    cout<<color<<" ";
};

Shape::~Shape()
{
    cout<<"destroy a shape"<<endl;
};