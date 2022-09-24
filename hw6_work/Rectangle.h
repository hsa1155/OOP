#ifndef RECTANGLE_H
#define RECTANGLE_H

#include<iostream>
#include<string>
#include"Shape.h"
using namespace std;
class Rectangle:public Shape
{
    private:
    int height;
    int width;
    public:
    Rectangle(const string&,int,int);
    ~Rectangle();
    void print();
    double get_area();
};



#endif
