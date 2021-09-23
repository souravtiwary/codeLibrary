#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int x){
        data = x;
        left = right = NULL;
    }
};

void inOrder(Node *root, vector<int> &arr){
    if (root == NULL){
        return;
    }
    inOrder(root->right, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

int countPair(Node *root1, Node *root2, int target){
    vector<int> arr ;
    int counter = 0;
    inOrder(root1, arr);
    unordered_map<int, bool> mpp;
    int sizeofTree1 = arr.size();
    for (int i = 0; i<sizeofTree1; i++){
        mpp[arr[i]] = true;
    }
    inOrder(root2, arr);
    for (int i = sizeofTree1; i<arr.size(); i++){
        int temp = target - arr[i];
        if (mpp.find(temp) != mpp.end()){
            counter++;
        }
    }
    return counter;
}

int main(){

    return 0;
}
