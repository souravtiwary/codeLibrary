#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

void maxPathSum(Node *root, int currsum, int &maxi){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    currsum += root->data;
    maxi = max(currsum, maxi);
    maxPathSum(root->left, currsum, maxi);
    maxPathSum(root->right, currsum, maxi);
}

int main(){
    int maxi = INT_MIN;
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(8);
    root->right->right = new Node(6);
    root->right->right->left = new Node(11);
    root->right->right->left->left = new Node(15);
    root->right->right->right = new Node(9);
    root->right->right->right->left = new Node(10);
    maxPathSum(root, 0, maxi);
    cout<<endl;
    cout<<maxi<<endl;
}