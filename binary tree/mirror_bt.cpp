#include<bits/stdc++.h>
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

void inorder(Node *node){
    if (node == NULL){
        return;
    }
    else{
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}

void modifyTree(Node *node){
    if (node == NULL){
        return;
    }
    else{
        struct Node* temp;
        modifyTree(node->left);
        modifyTree(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int main(){
     Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);
    inorder(root);
    modifyTree(root);
    cout<<endl;
    inorder(root);
}