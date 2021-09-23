#include <bits/stdc++.h>
using namespace std;
#define MAX 100

// Using array
class Stack{
    int top=-1;

    public:
        int a[MAX];
        bool push(int x);
        int pop();
        int peek();
        int isEmpty();
};

bool Stack::push(int x){
    if (top >= (MAX-1)){
        cout<<"Stack Overflow";
        return false;
    }
    top ++;
    a[top] = x;
    cout<<x<<" pushed into stack"<<" "<<top<<endl;
    return true;
}

int Stack::pop(){
    if (top < 0){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    cout<<a[top]<<" is poped"<<" "<<top<<endl;
    a[top] = 0;

    top -= 1;
    return 1;
}

int Stack::peek(){
    if (top < 0){
        cout<<"Stack is empty "<<endl;
        return -1;
    }
    return a[top];
}

int Stack:: isEmpty(){
    if (top < 0){
        cout<<"Empty"<<endl;
        return -1;
    }
    else{
        return 1;
    }
}

int main(){

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
}
// ================================================================

// Using Linklist

class StackNode {
    public:
        int data;
        StackNode* next;
};
//new block of memory / constructor
StackNode* newNode(int data){
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode *root){
    return !root;
}

//we are passing the address of root into function therefore **
void push(StackNode **root, int data){
    StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout<<data<<" is pushed in stack "<<(root)<<endl;
}

int pop(StackNode **root){
    if (isEmpty(*root)){
        return INT_MIN;
    }
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp -> data;
    free(temp);
    return popped;
}

void printStack(StackNode **root){
    StackNode *temp = *root;
    while((temp) != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


// int main(){
//  StackNode *root = NULL;
//  push(&root, 10);
//  push(&root, 20);
//  push(&root, 40);
//  push(&root, 50);
// //  cout<<pop(&root)<<endl;
// //  cout<<pop(&root)<<endl;
// //  cout<<pop(&root)<<endl;
// printStack(&root);
// }