#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int i){
        this->data = i;
        this->left = NULL;
        this->right = NULL;
    }
 
};

vector<int > reverseOrder(Node *root){
    stack <Node *> s;
    queue<Node *> q;
    vector <int> ans;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        s.push(root);
        if (root->right){
            q.push(root->right);
        }
        if (root->left){
             q.push(root->left);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top()->data);
        s.pop();
    }
    return ans;
}

int main(){
    return 0;
    struct Node * temp = new  Node(1);
}