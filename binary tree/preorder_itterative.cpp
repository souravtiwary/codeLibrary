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

void preOrder(Node *root){
    if (root == nullptr){
        return;
    }
    stack<Node *> s;
    Node *curr = root;
    s.push(root);
    while(!s.empty()){
        Node *curr = s.top();
        s.pop();
        cout<<curr->data<<" ";

        if (curr->right){
            s.push(curr->right);
        }
        if (curr->left){
            s.push(curr->left);
        }
    }
}
//Solution can be optimized by pushing only the right child to the stack

// Iterative function to perform pre-order traversal of the tree
void preorderIterative(Node *root)
{
    // return if tree is empty
    if (root == nullptr)
       return;
 
    // create an empty stack and push root node
    stack<Node*> stack;
    stack.push(root);
 
    // start from root node (set current node to root node)
    Node* curr = root;
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // if current node is not null, print it and push its right child
        // to the stack and move to its left child
        if (curr != nullptr)
        {
            cout << curr->data << " ";
 
            if (curr->right)
                stack.push(curr->right);
 
            curr = curr->left;
        }
        // else if current node is null, we pop a node from the stack
        // set current node to the popped node
        else
        {
            curr = stack.top();
            stack.pop();
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
    preOrder(root);
}