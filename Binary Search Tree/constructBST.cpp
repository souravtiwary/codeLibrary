#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node (int x){
        data = x;
        left = right = NULL;
    }
};

void inOrded(Node *root){
    if (root == NULL){
        return;
    }
    inOrded(root->left);
    cout<<root->data<<" ";
    inOrded(root->right);
}

// O(n^2) time and O(1) space
Node* constructBSTUtil(int pre[], int *preIdx, int low, int high, int size){
    if (*preIdx >= size || low > high){
        return NULL;
    }
    Node *root = new Node(pre[*preIdx]);
    *preIdx += 1;

    if (low == high){
        return root;
    }

    int i;
    for (i=low; i<=high; i++){
        if (pre[i] > root->data){
            break;
        }
    }
    root->left = constructBSTUtil(pre, preIdx, *preIdx, i-1, size);
    root->right = constructBSTUtil(pre, preIdx, i, high, size);
    return root;
}

// O(n) time and O(1) space
Node *constructBSTUtil(int pre[], int *preIdx, int key, int min, int max, int size){
    if (*preIdx >= size){
        return NULL;
    }
    Node *root = NULL;
    if (key > min && key < max){
        *preIdx += 1;
        root = new Node(key);

        if (*preIdx < size){
           root->left = constructBSTUtil(pre, preIdx, pre[*preIdx], min, key, size);
        }
        if (*preIdx < size){
            root->right = constructBSTUtil(pre, preIdx, pre[*preIdx], key, max, size);
        }
    }
    return root;
}

Node* constructBST(int pre[], int size){
    int preIdx = 0;
    return constructBSTUtil(pre, &preIdx, pre[0], INT_MIN, INT_MAX, size);
}

int main(){
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    Node *root = constructBST(pre, 6);
    inOrded(root);
}