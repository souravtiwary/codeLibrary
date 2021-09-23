#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;

    Node (int n){
        this->data = n;
        this->right = this->left = nullptr;
    }
};

void topView(Node *root){
    if (!root)
        return;
    Node *temp = root;
    stack<int> s;
    while(temp->right){
        temp = temp->right;
        s.push(temp->data);
    }
    temp = root;
    while(temp){
        s.push(temp->data);
        temp = temp->left;
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    cout<<"Following are nodes in top view of Binary Tree\n";
    topView(root);
    return 0;
}
