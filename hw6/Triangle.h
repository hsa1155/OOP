#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<iostream>
#include<string>
#include"Shape.h"
using namespace std;
class Triangle:public Shape
{
    private:
    int height;
    int base;
    public:
    Triangle(const string&,int,int);
    ~Triangle();
    void print();
    double get_area();
};


#endif
