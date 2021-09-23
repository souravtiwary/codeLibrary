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
//Node *headNode = NULL;

void inOrder(Node *root){
    if (root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void bToDLLUtil(Node *root, Node **head_ref)
{
    // Base cases
    if(root == NULL)
        return;

    // Recursively convert right subtree
    bToDLLUtil(root->right, head_ref);

    // insert root into DLL
    root->right = *head_ref;

    // Change left pointer of previous head
    if (*head_ref != NULL)
        (*head_ref)->left = root;

    // Change head of Doubly linked list
    *head_ref = root;

    // Recursively convert left subtree
    bToDLLUtil(root->left, head_ref);
}

void printList(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->right;
    }
    cout<<endl;
}

Node* bToDLL(Node *root)
{
    Node *head = NULL;
    bToDLLUtil(root,&head);
    return head;
    
}

int main(){
    Node *root = new Node(10);  
    root->left = new Node(12);  
    root->right = new Node(15);  
    root->left->left = new Node(25);  
    root->left->right = new Node(30);  
    root->right->left = new Node(36);  
    inOrder(root);
    cout<<endl;
    Node *headNode = bToDLL(root); 
    printList(headNode);
    return 0;
}