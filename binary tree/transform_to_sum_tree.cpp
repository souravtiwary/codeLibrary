#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int sumTree(Node *node){
    if (node == NULL)
        return 0;
    int oldValue = node->data;
    node->data = sumTree(node->left) + sumTree(node->right);
    return node->data + oldValue;
}

int main(){

}