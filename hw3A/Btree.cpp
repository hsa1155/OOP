#include<bits/stdc++.h>
#include"Tnode.cpp"
using namespace std;

typedef Tnode *TnodePtr;
class Btree
{
private:
    TnodePtr root;
    bool areMirrors(TnodePtr root1, TnodePtr root2)
    {
        bool sta;
        if((root1==NULL&&root2!=NULL) ||(root1!=NULL&&root2==NULL)){return false;}
        if(root1==NULL&&root2==NULL)  return true;
        if(root1->val!=root2->val)
        {
            return false;
        }
        sta=areMirrors(root1->left,root2->right);
        if(sta==false) return false;
        sta=areMirrors(root1->right,root2->left);
        return sta;

    }
public:
    Btree(TnodePtr node)
    {
        root = node;
    }
    bool isPalindromicTree()
    {
        return areMirrors(root, root);
    }
};