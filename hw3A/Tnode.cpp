#include<bits/stdc++.h>
using namespace std;
ifstream inp("treenode.txt");
ofstream out("tree_ans.txt", ios::out);
class Tnode
{
public:
    Tnode *left, *right;
    int val;
    Tnode(int x)
    {
        cout << "a node is built. " << endl;
        val = x;
        cout<<"val="<<x<<endl;
        left = NULL;
        right = NULL;
    }
    Tnode *buildnode()
    {
        int y;
        inp >> y;
        if (y == -1)
            return NULL;
        else
        {
            Tnode *newnode = new Tnode(y);
            newnode->left = buildnode();
            newnode->right = buildnode();
            return newnode;
        }
    }
    void print(Tnode *root)
    {
        if (root == NULL)
        {
            cout<<-1<<" ";
            out<<-1<<" ";
            return;
        }
        cout << root->val << " ";
        out<<root->val<<" ";
        print(root->left);
        print(root->right);
    }
    void destroy(Tnode *root)
    {
        if(root ==NULL) return;
        destroy(root->left);
        destroy(root->right);
        //cout<<"destroy"<<root->val<<endl;;
        delete root;
    }
};