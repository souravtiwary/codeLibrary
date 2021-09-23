#include <bits/stdc++.h>
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
void inorder(Node *root, int k, int &i, int &res){
    if (root == NULL || i >= k){
        return;
    }
    inorder(root->left, k, i, res);
    i += 1;
    if (i == k){
        res = root->data;
        return;
    }
    inorder(root->right, k, i, res);
}
int KthSmallestElement(Node *root, int k)
{
    //add code here.
    int i = 0;
    int res = -1;
    inorder(root, k, i, res);
    return res;
}