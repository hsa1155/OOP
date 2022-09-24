#include <bits/stdc++.h>
#include "Btree.cpp"
using namespace std;

int main()
{

    int x;
    while (inp >> x)
    {
        TnodePtr node = new Tnode(x);
        node->left = node->buildnode();
        node->right = node->buildnode();
        Btree *palTree = new Btree(node);
        node->print(node);
        cout << endl;
        if (palTree->isPalindromicTree())
        {
            cout << "(true)is a Palindromic Tree" << endl;
            out << "(true)is a Palindromic Tree" << endl;
        }
        else
        {
            cout << "(false)is not a Palindromic Tree" << endl;
            out << "(false)is not a Palindromic Tree" << endl;
        }
        cout << endl;
        out << endl;

        node->destroy(node);
    }
}