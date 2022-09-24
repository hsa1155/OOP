#include <bits/stdc++.h>
#include"node.cpp"
using namespace std;
ofstream out("stack_ans.txt", ios::out);
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
        if(size==0) {cout<<"stack is empty(true)"<<endl;out<<"stack is empty(true)"<<endl;}
        else {cout<<"stack is not empty(false)"<<endl;out<<"stack is not empty(false)"<<endl;}
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
    int pop()
    {
        if(size==0)
        {
            cout<<"The stack is empty,there's nothing to pop"<<endl;
            out<<"The stack is empty,there's nothing to pop"<<endl;
            return 0x3f3f3f3f;
        }
        else
        {
            int num=top->item;
            cout<<"pop "<<top->item<<endl;
            out<<"pop "<<top->item<<endl;
            nodePtr tmp=top;
            
            top=top->next;
            delete tmp;

            

            
            size--;
            return num;
        }

    }
};
