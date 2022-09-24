#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>
#include<string>
using namespace std;
class Shape
{
    private:
    string color;
    public:
    Shape(const string&);
    virtual ~Shape();
    virtual void print();
    virtual double get_area()=0;
};


#endif
