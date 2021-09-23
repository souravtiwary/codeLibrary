#include <bits/stdc++.h>
#include <vector>
#include<queue>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> levelOrderTraversal(Node *node){
    vector <int> ans;
    if (node == NULL){
        return ans;
    }
    queue<Node *> q;
    q.push(node);
    while(!q.empty()){
        struct Node* temp = q.front();
        ans.push_back(q.front()->data);
        if (q.front()->left != NULL)
            q.push(q.front()->left);
        if (q.front()->right != NULL){
            q.push(q.front()->right);
        }
        q.pop();
    }
    return ans;
}

int main(){
    return 0;
}