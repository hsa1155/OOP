#include<bits/stdc++.h>
#include"mystack.cpp"
using namespace std;
typedef node* nodePtr;
int main()
{
    mystack stack;
    
    while(1)
    {
        cout<<"input 1 to push,2 to pop,3 to empty,-1 to end"<<endl;
        int x;
        cin>>x;
        if(x==1)
        {
            int y;
            cout<<"input a int to push"<<endl;
            cin>>y;
            stack.push(y);

        }
        if(x==2)
        {
            stack.pop();
        }
        if(x==3)
        {
            stack.empty();

        }
        if(x==-1)
        {
            break;
        }
    }

    return 0;
}
