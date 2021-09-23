#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

/* int height(Node *root){
    int hl=0, hr=0;
    Node *temp = root;
    if (temp == nullptr)
        return 0;
    else{
        int hl = height(temp->left);
        int hr = height(temp->right);

        if (hl > hr)
            return hl+1;
        else
            return hr + 1;
    }
    return max(hl+1, hr+1);
} */

// using level order print 1st element in level
void leftview(Node *root){
    queue<Node *> q;
    if (root == nullptr)
        return ;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for (int i=1; i<=n; i++){
            Node *temp = q.front();
            q.pop();
            if (i == 1){
                cout<<temp->data<<" ";
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right->left = new Node(14);
    leftview(root);
    return 0;
}
