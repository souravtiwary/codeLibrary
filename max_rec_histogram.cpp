#include <bits/stdc++.h>
using namespace std;

int areaMax( int i,int top, int arr[]){
    int maxArea = 0;
    maxArea = arr[top] * (i-top+1);
    return maxArea;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }
        stack<int> s;
        int i=0;
        int top = 0; 
        int maxArea = 0;
        int area=0;
        while(i < n){
            if (s.empty() || arr[s.top()] < arr[i] ){
                s.push(i);
                i++;
            }
            else{

                top = s.top();
                s.pop();
                if (s.empty()){
                   area = arr[top] * i;
                }else{
                    area = arr[top] * (i - s.top() - 1);
                }
            }
            if (area > maxArea){
                maxArea = area; 
            }
        }
        while(!s.empty()){
            top = s.top();
                s.pop();
                if (s.empty()){
                   area = arr[top] * i;
                }else{
                    area = arr[top] * (i - s.top() - 1);
                }
            if (area > maxArea){
                maxArea = area; 
            }
        }
        cout<<maxArea<<endl;
    }
}