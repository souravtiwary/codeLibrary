#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

int isBalancedTree(Node *node){
    if(node == NULL){
        return 0;
    }
    int lh = isBalancedTree(node->left);
    int rh = isBalancedTree(node->right);
    if(lh == -1 || rh == -1) return -1;
    if(abs(lh-rh) >= 1){
        return -1;
    }
    
    return 1+max(lh, rh);
}

int main(){

}