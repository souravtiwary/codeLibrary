#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int x){
        data = x;
        left = right = nullptr;
    }
};
void traverseTree(Node *root, unordered_map<int, bool>&nonleaf, unordered_map<int , bool>&leaf){
    if (root == NULL){
        return;
    }
    if (root->left == NULL && root->right == NULL){
        leaf.insert(make_pair(root->data, true));
    }
    else{
        nonleaf.insert(make_pair(root->data, true));
    }
    
    traverseTree(root->left, nonleaf, leaf);
    traverseTree(root->right, nonleaf, leaf);
}

bool isDeadEnd(Node *root){
    unordered_map<int, bool> nonleaf, leaf;
    nonleaf.insert(make_pair(0, true));
    traverseTree(root, nonleaf, leaf);
    for (auto it:leaf){
        if (nonleaf.find(it.first-1) != nonleaf.end() && nonleaf.find(it.first+1) != nonleaf.end()){
            return true;
        }
    }
    return false;
}