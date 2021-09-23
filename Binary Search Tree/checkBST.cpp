#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node (int x){
        data = x;
        left = right = NULL;
    }
};

bool isBSTUtil(Node *root, int min, int max){
    if (root == NULL) return true;

    if (root->data < min || root->data > max)
        return false;
     return isBSTUtil(root->left, min, root->data-1) && // Allow only distinct values  
        isBSTUtil(root->right, root->data+1, max); // Allow only distinct values 
}

bool isBST(Node *root){
    return (isBSTUtil(root, INT_MIN, INT_MAX));
}