
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int node;
    struct Node *left, *right;

    Node (int node)
    {
        this->node = node;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void postOrder(Node *node)
{
    struct Node *temp = node;
    if (temp == nullptr)
    {
        return;
    }
    postOrder(temp->left);
    postOrder(temp->right);
    cout << temp->node << " ";
}

void postOrderRecursive(Node *root){
    stack<Node *> s;
    s.push(root);
    stack<int> ans;

    while(!s.empty()){
        Node *curr = s.top();
        s.pop();
        ans.push(curr->node);
        if(curr->left){
            s.push(curr->left);
        }
        if (curr->right)
            s.push(curr->right);
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left =new  Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    postOrder(root);
    cout<<endl;
    postOrderRecursive(root);
    return 0;
}
