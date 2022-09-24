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
};