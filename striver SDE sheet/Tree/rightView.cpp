#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

// O(n) O(k) 1 <= k <= 2^l
vector<int> RightView(Node * root){
    vector<int> left_viewof_tree;
    queue<Node *> level;
    level.push(root);
    while(!level.empty()){
        int size = level.size();
        for(int i=0; i<size; i++){
            Node *curr = level.front();
            level.pop();
            if(size == i+1){
                left_viewof_tree.push_back(curr->data);
            }
            if(curr->left) level.push(curr->left);
            if(curr->right) level.push(curr->right);
        }
    }
    return left_viewof_tree;
}

// O(N) O(H)
void RightViewRecursion(Node *root, int lvl, vector<int> &ans){
    if(root == NULL) {
        return;
    }
    if(ans.size() == lvl){
        ans.push_back(root->data);
    }
    RightViewRecursion(root->right, lvl+1, ans);
    RightViewRecursion(root->left, lvl+1, ans);
}