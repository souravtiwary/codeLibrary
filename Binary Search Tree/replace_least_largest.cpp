#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node (int x){
        data = x;
        left = right = NULL;
    }
};

void insert_bst(int x, Node* &node, Node* &succ ){
    //cout<<"insert"<<endl;
    if (node == NULL){
        node = new Node(x);
        return;
    }
    if (x < node->data){
        succ = node;
        insert_bst(x, node->left, succ);
    }
    else if (x >= node->data){
        insert_bst(x, node->right, succ);
    }
}

void replace_arr(int arr[], int n){
    Node *root = NULL;
    //cout<<"repalce";
    for (int i=n-1; i>=0; i--){
        Node *succ = NULL;
        insert_bst(arr[i], root, succ);
        if (succ){
            arr[i] = succ->data;
        }
        else{
            arr[i] = -1;
        }
    }
}

int main(){
        int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92,
                  43, 3, 91, 93, 25, 80, 28 };
        int n = sizeof(arr)/ sizeof(arr[0]);
        //cout<<n;
        replace_arr(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        return 0;
}
