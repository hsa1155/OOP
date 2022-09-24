#include <bits/stdc++.h>
#include"node.cpp"
using namespace std;

typedef node* nodePtr;
class mystack
{
    private:
    nodePtr top;
    int size;
    public:
    mystack()
    {
        cout<<"Constructing a Stack"<<endl;
        top=0;
        size=0;
    }
    ~mystack()
    {
        cout << "Destructing a Stack" << endl;
        while(top!=NULL)
        {
            pop();
        }
    }
    void const empty()
    {
        if(size==0) cout<<"stack is empty(true)"<<endl;
        else cout<<"stack is not empty(false)"<<endl;
    }
    void push(int x)
    {
        if(size==0)
        {
            top = new node(x,NULL);
            size++;
            return;
        }
        else
        {
            nodePtr newnode= new node(x,top);
            top=newnode;
            size++;
            return;

        }

    }
    void pop()
    {
        if(size==0)
        {
            cout<<"The stack is empty,there's nothing to pop"<<endl;
            return;
        }
        else
        {
            cout<<"pop "<<top->item<<endl;
            
            nodePtr tmp=top;
            
            top=top->next;
            delete tmp;

            

            
            size--;
            return;
        }

    }
};
