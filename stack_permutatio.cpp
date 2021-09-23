#include<bits/stdc++.h>
#include <queue>
using namespace std;

bool checkStackPermutation(int a[], int b[], int size){
    queue<int> input;
    for (int i=0; i<size; i++){
        input.push(a[i]);
    }
    queue<int> output;
    for (int i=0; i<size; i++){
        output.push(b[i]);
    }
    stack<int> s;
    while(!input.empty()){
        int ele = input.front();
        input.pop();
        if (ele == output.front()){
            output.pop();
            while(!s.empty() && s.top() == output.front()){
                s.pop();
                output.pop();
            }
        }
        else{
            s.push(ele);
        }
    }
    return (input.empty() && s.empty());
}

int main(){
    int arr1[] = {1,2,3};
    int arr2[] = {2,1,3};
    checkStackPermutation(arr1, arr2, 3);    
}