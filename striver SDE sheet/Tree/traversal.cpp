#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int data){
        left = right = NULL;
        val = data;
    }
};

vector<int> inorder(Node *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<Node*> s;
    Node *node = root;
    while(!s.empty()){
        if(node != NULL){
            s.push(node);
            node = node->left;
        }
        else{
            node = s.top();
            s.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}

vector<int> postorder(Node *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<Node*> s;
    
}

int main(){

}