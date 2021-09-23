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

bool isBST(Node *root, int min, int max){
    if (root == NULL){
        return true;
    }
    if (root->data >= min && root->data <= max){
        return isBST(root->left, min, root->data-1) && isBST(root->right, root->data+1, max);
    }else{
        return false;
    }
    
}

int sizeofBST(Node *root){
    if (root == NULL){
        return 0;
    }
    return sizeofBST(root->left) + sizeofBST(root->right)+1;
}

int largestBst(Node *root)
{
	//Your code here
	if (root == NULL){
        return 0;
    }
    if (isBST(root, INT_MIN, INT_MAX)){
        return sizeofBST(root);
    }
    int left = largestBst(root->left);
    int right = largestBst(root->right);
    return max(left, right);
}