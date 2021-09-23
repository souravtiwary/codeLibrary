#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};

void inorder(Node *root){
    stack<Node *> s;
    Node *curr = root;
    while(!s.empty() || curr!=nullptr){
        if (curr != nullptr){
            s.push(curr);
            curr = curr->left;
        }
        else{
            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
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
    inorder(root);
}