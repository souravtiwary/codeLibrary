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

bool pathToNode(Node *root, int k, vector<int> &ans){
    if(root == NULL){
        return false;
    }
    if(root->data == k){
        ans.push_back(root->data);
        return true;
    }
    ans.push_back(root->data);
    //cout<<root->data<<" ";
    if(pathToNode(root->left, k, ans) 
            || pathToNode(root->right, k, ans)){
                return true;
            }
    ans.pop_back();
    return false;
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
    root->right->right->right = new Node(9);
    root->right->right->left = new Node(10);

    vector<int> ans;
    pathToNode(root, 10, ans);
    for(int x : ans){
        cout<<x<<" ";
    }
}