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
Node *root = NULL;

void insertIntoBinaryTree(int x){
    if(!root){
        root = new Node(x);
        return;
    }
    Node *temp = root;
    Node *prev = root;
    while(temp){
        if (temp->data <= x){
            prev = temp;
            temp = temp->right;
        }
        else{
            prev = temp;
            temp = temp->left;
        }
    }
    Node *node = new Node(x);
    if (x >= prev->data){
        prev->right = node;
    }
    else{
        prev->left = node;
    }
}

void printInorder(Node *node){
    if (!node){
        return;
    }
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

bool searchIntoBinary(int x){
    if (!root){
        return false;
    }
    Node *temp = root;
    while(temp){
        if (temp->data == x){
            return true;
        }
        else if (temp->data < x){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return false;
}

Node* deleteNode(Node *root, int target){
    if (root == NULL) return NULL;

    if (target > root->data){
        root->right = deleteNode(root->right, target);
        return root;
    }
    else if (target < root->data){
        root->left = deleteNode(root->left, target);
        return root;
    }
    if (root->right == NULL){
        Node *temp = root->left;
        delete root;
        return temp;
    }
    else if(root->right == NULL) {
        Node *temp = root->left;
        delete root;
        return temp;
    }
    else{
        Node *parent = root;
        Node *child = root->right;
        while(child->left != NULL){
            parent = child;
            child = child->left;
        }
        if (parent == root){
            parent->right = child->right;
        }
        else{
            parent->left = child->right;
        }
        root->data = child->data;
        delete child;
        return root;
    }
}

int main(){
    insertIntoBinaryTree(8);
    insertIntoBinaryTree(3);
    insertIntoBinaryTree(10);
    insertIntoBinaryTree(1);
    insertIntoBinaryTree(6);
    insertIntoBinaryTree(14);
    insertIntoBinaryTree(4);
    insertIntoBinaryTree(7);
    insertIntoBinaryTree(13);
    printInorder(root);
    deleteNode(root, 6);
    cout<<endl;
    printInorder(root);
    cout<<endl<<searchIntoBinary(14);
    return 0;
}