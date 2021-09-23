#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

Node* LCA(Node *root, Node *x, Node *y){
    if(root == NULL){
        return NULL;
    }
    Node *left = LCA(root->left, x, y);
    Node *right = LCA(root->right, x, y);

    if(left == root){
        left = root;
    }
    if(right == root){
        right = root;
    }
    if(left && right){
        return root;
    }
    if(left){
        return left;
    }
    if(right){
        return right;
    }
    return nullptr;
}

int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(8);
    root->right->right = new Node(6);
    root->right->right->left = new Node(11);
    root->right->right->left->left = new Node(15);
    root->right->right->right = new Node(9);
    root->right->right->right->left = new Node(10);
}