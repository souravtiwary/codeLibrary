#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int x){
        data = x;
        left = right = NULL;
    }
};

void inOrder(Node *root, vector<int> &arr){
    if (root == NULL){
        return ;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

void constructBST(Node *root, vector<int> arr, int *ptr){
    if(root == NULL){
        return;
    }
    constructBST(root->left, arr, ptr);

    root->data = arr[*ptr];
    *ptr += 1;

    constructBST(root->right, arr, ptr);
}

Node *binaryTreeToBST (Node *root)
{
    vector<int> arr;
    inOrder(root, arr);
    sort(arr.begin(), arr.end());
    int i = 0;
    constructBST(root, arr, &i);
    return root;
}

void printInorder(Node *root){
    if (root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    Node *root = new Node(10); 
    root->left = new Node(30); 
    root->right = new Node(15); 
    root->left->left = new Node(20); 
    root->right->right = new Node(5); 
    root = binaryTreeToBST(root);
    printInorder(root);
}