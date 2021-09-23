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
    if (root == NULL) 
        return;
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

Node* balancedBSTUtil(vector<int> arr, int start, int end){
    if (start > end){
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node (arr[mid]);
    root->left = balancedBSTUtil(arr, start, mid-1);
    root->right = balancedBSTUtil(arr, mid+1, end);

    return root;
}

Node* balancedBST(Node *root){
    vector<int> arr;
    inOrder(root, arr);
    root = balancedBSTUtil(arr, 0, arr.size()-1);
    return root;
}

void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 

int main(){
    Node* root = new Node(10); 
    root->left = new Node(8); 
    root->left->left = new Node(7); 
    root->left->left->left = new Node(6); 
    root->left->left->left->left = new Node(5); 
    preOrder(root);
    cout<<endl;
    root = balancedBST(root);
    preOrder(root);
    cout<<endl;
}