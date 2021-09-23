#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
};

node* newNode(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}

int heightOfBinaryTree(node *root){
    if (root == NULL){
        return 0;
    }
    int lheight = heightOfBinaryTree(root->left);
    int rheight = heightOfBinaryTree(root->right);

    if (lheight > rheight){
        return (lheight+1);
    }
    return (rheight+1);

}

int main(){
    return 0;
}

