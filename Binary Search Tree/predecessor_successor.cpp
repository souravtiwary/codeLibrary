#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node (int x){
        key = x;
        left = right = NULL;
    }
};
 

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    Node* p=NULL,*s=NULL;
    while(root && root->key!=key)
    {
        if(root->key<key)
        {
            p=root;
            root=root->right;
        }
        else
        {
            s=root;
            root=root->left;
        }
    }
    if(!root)
    {
        pre=p;
        suc=s;
        return;
    }
    if(!root->right)
    suc=s;
    else
    {
        Node* curr=root->right;
        while(curr->left)
        curr=curr->left;
        suc=curr;
    }
    if(!root->left)
    pre=p;
    else
    {
        Node* curr=root->left;
        while(curr->right)
        curr=curr->right;
        pre=curr;
    }
}