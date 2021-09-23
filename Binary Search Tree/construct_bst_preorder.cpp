// not understood

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int x){
        data = x;
        left = right = nullptr;
    }
};

// void insert(Node*& root, int x){
//     if (root == NULL){
//         root = new Node(x);
//         return;
//     }
//     Node *node = new Node(x);
//     Node *temp = root;
//     Node *prev = root;
//     while(temp){
//         prev = temp;
//         if (temp->data >= x){
//             temp = temp->right;
//         }
//         else{
//             temp = temp->left;
//         }
//     }
//     if (prev->data >= x){
//         prev->right = node;
//     }
//     else{
//         prev->left = node;
//     }
// }

// Node *constructTree(int pre[], int size){
//     if (size == 0){
//         return NULL;
//     }
//     Node *root = NULL;
//     for (int i=0; i<size; i++){
//         insert(root, pre[i]);
//     }
//     return root;
// }

int main(){

}