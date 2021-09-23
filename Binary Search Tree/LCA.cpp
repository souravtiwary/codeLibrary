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

Node* LCA(Node *root, int n1, int n2){
    Node *temp = root;
    while(temp){
        if (temp->data == n1){
            return temp;
        } 
        if (temp->data == n2){
            return temp;
        }
        if (n1 > temp->data && n2 > temp->data){
            temp = temp->right;
        }
        else if (n1 < temp->data && n2 < temp->data){
            temp = temp->left;
        }
        else{
            return temp;
        }
    }
    return temp;
}