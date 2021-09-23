#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node (int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int findIndex(string s, int si, int ei){
    cout<<"Inside findIndex"<<endl;
    if (ei < si)
        return -1;
    stack<char> stack;
    for (int i = si; i<= ei; i++){
        if (s[i] == '(')
            stack.push(s[i]);
        else if (s[i] == ')'){
            if (stack.top() == '('){
                stack.pop();
                if (stack.empty()){
                    return i;
                }
            }
        }
    }
    return -1;
}

Node* makeTreeFromString(string s, int si, int ei){
    if (si > ei)
        return NULL;
    Node *root = new Node(s[si] - '0');
    int idx = -1;
    if (si + 1 <= ei && s[si+1] == '('){
        idx = findIndex(s, si+1, ei);
    }
    if (idx != -1){
        root->left = makeTreeFromString(s, si+2, idx-1);
        root->right = makeTreeFromString(s, idx+2, ei-1);
    }
    return root;
}

void preOrder(Node *root){
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    string s = "4(2(3)(1))(6(5))";
    Node *root = makeTreeFromString(s, 0, s.length()-1);
    preOrder(root);
    return 0;
}