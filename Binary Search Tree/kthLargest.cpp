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

void kthLargestUtil(Node *root, int k, int &c, int &res)
{
    if (root == NULL || c >= k)
        return;
    
    kthLargestUtil(root->right, k, c, res);
    
    c++;
    if (c == k)
    {
		res = root->data;
        return;
    }
    
    kthLargestUtil(root->left, k, c, res);
}

int kthLargest(Node *root, int k)
{
    int c = 0;
    int res = -1;
    kthLargestUtil(root, k, c, res);
    return res;
}