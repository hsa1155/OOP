#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int item;
    node* next;
    node(int x, node *t)
    {
        cout<<"A node is built"<<endl;
        item = x;
        next = t;
    }
    node(int x)
    {
        cout<<"A node is built"<<endl;
        item = x;
        next = NULL;

    }
    node()
    {
        cout<<"A node is built"<<endl;
        item=0;
        next = NULL;

    }
};