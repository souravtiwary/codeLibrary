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

void topView (Node *root){
    if (root == NULL){
        return;
    }
    Node *temp = NULL;
    queue<pair<Node *, int>> queue;
    //map because we want left most to right most
    map<int, int> mp;
    queue.push({root, 0});
    while(!queue.empty()){
        temp = queue.front().first;
        int d = queue.front().second;
        queue.pop();
        if (mp.find(d) == mp.end()){
            mp[d] = temp->data;
        }

        if (temp->left){
            queue.push({temp->left, d-1});
        }
        if (temp->right){
            queue.push({temp->right, d+1});
        }

    }
    for (auto i: mp){
        cout<<i.second<<" ";
    }
}

int main(){
    return 0;
}