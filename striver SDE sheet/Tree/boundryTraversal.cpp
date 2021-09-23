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

bool isLeaf(Node *node){
    if(node == NULL){
        return false;
    }
    if(node->right == NULL && node->left == NULL){
        return true;
    }
    return false;
}

void leftBoundry(Node *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    Node *curr = root;
    while(curr){
        if(isLeaf(curr)) break;;
        ans.push_back(curr->data);
        cout<<curr->data<<" " ;
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    
}

void leafBoundry(Node *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(isLeaf(root)){
        ans.push_back(root->data);
        cout<<root->data<<" ";
    }
    leafBoundry(root->left, ans);
    leafBoundry(root->right, ans);
}

void rightBoundry(Node *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    Node *curr = root;
    stack<int> s;
    while(curr){
        if(isLeaf(curr)) break;
        cout<<curr->data<<" ";
        s.push(curr->data);
        if(curr->right){
            curr = curr->right;
        }
        else
            curr = curr->left;
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
}

vector<int> boundryOrder(Node *root){
    vector<int> ans;
    if(!isLeaf(root)){
        cout<<root->data<<" ";
        ans.push_back(root->data);
    }
    leftBoundry(root->left, ans);
    cout<<endl;
    leafBoundry(root, ans);
    cout<<endl;
    rightBoundry(root->right, ans);
    cout<<endl;

    return ans;

}

int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->right = new Node(6);
    vector<int> ans = boundryOrder(root);
    for(int x : ans){
        cout<<x<<" ";
    }
}