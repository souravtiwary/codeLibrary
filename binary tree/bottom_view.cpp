#include <bits/stdc++.h>
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

void bottomView(Node *root){
    if (root == NULL){
        return;
    }
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    Node *temp = NULL;
    while(!q.empty()){
        temp = q.front().first;
        int d =  q.front().second;
        q.pop();
        mp[d] = temp->data;
        if (temp->left){
            q.push({temp->left, d-1});
        }
        if (temp->right){
            q.push({temp->right, d+1});
        }
    }
    vector<int> ans;
    for (auto i: mp){
        ans.push_back(i.second);
    }
    for (auto i : ans){
        cout<<i<<" ";
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);
    bottomView(root);
    
    return 0;
}