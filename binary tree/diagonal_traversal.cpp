#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void diagonalUtil(Node *root, int s, map<int, vector<int>> &ans)
{
    if (!root){
        return;
    }
    ans[s].push_back(root->data);

    diagonalUtil(root->left, s+1, ans);
    diagonalUtil(root->right, s, ans);
}

void diagonalTraversal(Node *root){
    if (!root)
        return ;
    map<int, vector<int>> ans;
    diagonalUtil(root, 0, ans);
    for (auto i : ans){
        vector<int> it = i.second;
        for (auto x:it){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    diagonalTraversal(root);
}