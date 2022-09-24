#include<iostream>
#include<string>
#include<vector>
#include <typeinfo>
#include"Shape.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
using namespace std;
int main()
{
    vector<Shape*> ptr;
    
    Circle* c1=new Circle("black",1);
    Circle* c2=new Circle("white",4);
    Triangle* t1=new Triangle("red",1,1);
    Triangle* t2=new Triangle("blue",3,4);
    Rectangle* r1=new Rectangle("yellow",1,1);
    Rectangle* r2=new Rectangle("green",5,10);
    
   /*
    Circle c1("black",1);
    Circle c2("white",4);
    Triangle t1("red",1,1);
    Triangle t2("blue",3,4);
    Rectangle r1("yellow",1,1);
    Rectangle r2("green",5,10);
    */
    ptr.push_back(c1);
    ptr.push_back(c2);
    ptr.push_back(t1);
    ptr.push_back(t2);
    ptr.push_back(r1);
    ptr.push_back(r2);
    for(int i=0;i<ptr.size();i++)
    {
        ptr[i]->print();
        //cout<<"area="<<ptr[i]->get_area()<<endl<<endl;
        //cout<<typeid(&c1).name()<<endl;
    }
    cout<<"print only circles"<<endl;
    for(int i=0;i<ptr.size();i++)
    {
        if(typeid(*ptr[i])==typeid(Circle))
        {
        ptr[i]->print();
        //cout<<"area="<<ptr[i]->get_area()<<endl<<endl;
        }
        
    }
    for(int i=ptr.size();i>=0;i--)
    {
        delete ptr[i];
    }
    ptr.clear();

}