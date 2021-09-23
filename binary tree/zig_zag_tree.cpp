#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

vector<int> zigzagtraversal(Node *root){
    vector<int> ans;
    if (root == NULL){
        return ans;
    }
    stack <Node *> curr ;
    stack<Node *> next;
    curr.push(root);
    bool lefttoright = true;
    while (!curr.empty()) {
        Node *temp = curr.top();
        curr.pop();
        if (temp){
            
            ans.push_back(temp->data);
            cout<<temp->data<<" ";
            if (lefttoright){
                if (temp->left){
                    next.push(temp->left);
                }
                if (temp->right){
                    next.push(temp->right);
                }
                
            }else{
                if (temp->right){
                    next.push(temp->right);
                }
                if (temp->left){
                    next.push(temp->left);
                }
            }
        }
        if (curr.empty()){
            lefttoright = !lefttoright;
            swap(curr, next);
        }
    }
    return ans;
}

int main(){
    struct Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(7); 
    root->left->right = new Node(6); 
    root->right->left = new Node(5); 
    root->right->right = new Node(4); 
    cout << "ZigZag Order traversal of binary tree is \n"; 
  
    zigzagtraversal(root);
}