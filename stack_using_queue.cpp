#include <bits/stdc++.h>
using namespace std;

class QueueStack {
    queue<int> q1;
    queue<int> q2;
    public: 
        void push(int);
        int pop();
};

void QueueStack :: push(int x){
    q2.push(x);
    while(!q1.empty()){
        int front  = q1.front();
        q1.pop();
        q2.push(front);
    }
    swap(q1, q2);
}

int QueueStack :: pop(){
    int front = q1.front();
    q1.pop();
    return front;
}