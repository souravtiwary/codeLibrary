#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

vector<int> bottomView(Node *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> mpp;
    queue<pair<Node*, int>> q; // node, x-co;
    q.push({root, 0});
    while(!q.empty()){
        Node *curr = q.front().first;
        int line = q.front().second;
        q.pop();
        mpp[line] = curr->data;
        if(curr->left){
            q.push({curr->left, line+1});
        }
        if(curr->right){
            q.push({curr->right, line-1});
        }
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}