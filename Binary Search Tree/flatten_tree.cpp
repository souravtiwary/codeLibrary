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

void inOrder(Node *root, Node *&prev){
    if (root == NULL){
        return;
    }
    inOrder(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    inOrder(root->right, prev);
}

Node* flattenTree(Node *root){
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    inOrder(root, prev);
    Node *ret = dummy->right;
    delete dummy;
    return ret;
}

void print(Node *curr){
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

int main() 
{ 
    Node* root = new Node(5); 
    root->left = new Node(3); 
    root->right = new Node(7); 
    root->left->left = new Node(2); 
    root->left->right = new Node(4); 
    root->right->left = new Node(6); 
    root->right->right = new Node(8); 
  
    // Calling required function 
    print(flattenTree(root)); 
  
    return 0; 
}