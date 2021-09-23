#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node (int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printLeftOfTree(Node *root, vector<int> &ans){
    if (root == nullptr)
        return;
    // for top-bottom we print then call function
    if (root->left){
        ans.push_back(root->data);
        printLeftOfTree(root->left, ans);
    }
    else if (root->right){
        ans.push_back(root->data);
        printLeftOfTree(root->right, ans);
    }
}

void printLeave(Node *root, vector<int> &ans){
    if (root == NULL)
        return;
    printLeave(root->left, ans);
    if (!(root->left) && !(root->right)){
        ans.push_back(root->data);
    }
    printLeave(root->right, ans);
}

void printRight(Node *root, vector<int> &ans){
    if (root == nullptr)
        return;
    if (root->right){
        printRight(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left){
        printRight(root->left, ans);
        ans.push_back(root->data);
    }
    return ;
}

vector<int> printBoundry(Node *root){
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    //print left of the tree
    
    printLeftOfTree(root->left, ans);
    //print leaf nodes
    printLeave(root->left, ans); //print left leaf 
    printLeave(root->right, ans); //print right leaf
    //print right of tree
    printRight(root->right, ans);
    return ans;
}

int main(){
    Node *root = new Node(20);
    root->left = new Node(8); 
    root->left->left = new Node(4); 
    root->left->right = new Node(12); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 
    root->right = new Node(22); 
    root->right->right = new Node(25); 
    return 0;
}