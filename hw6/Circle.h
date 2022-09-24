#ifndef CIRCLE_H
#define CIRCLE_H

#include<iostream>
#include<string>
#include"Shape.h"
using namespace std;
class Circle:public Shape
{
    private:
    int radius;
    public:
    Circle(const string&,int);
    ~Circle();
    void print();
    double get_area();
};


#endif
