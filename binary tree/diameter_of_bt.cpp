#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int heightOfBT(Node *node){
    if (node == NULL){
        return 0;
    }
    return 1+ max(heightOfBT(node->left) , heightOfBT(node->right));
}

int diameter(Node *node){
    if (node == NULL){
        return 0;
    }
    int height = heightOfBT(node->left)+heightOfBT(node->right)+1;
    int left  = diameter(node->left);
    int right = diameter(node->right);

    return max(height, max(right, left));
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);
    cout<<diameter(root)<<endl;
    return 0;
}