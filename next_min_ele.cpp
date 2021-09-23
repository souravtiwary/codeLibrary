#include <bits/stdc++.h>
using namespace std;

vector <long long> nextlargestElement(long long arr[], int n){
    vector<long long> ans(n, -1);
    //fill(ans.begin(), ans.end(), -1);
    stack<int> s;
    for (int i=0; i<n; i++){
        if (s.empty()){
            s.push(i);
        }
        else{
            if (arr[s.top()] >= arr[i]){
                s.push(i);
            }
            else{
                while(!s.empty() && arr[s.top()] < arr[i]){
                    ans[s.top()] = arr[i];
                    s.pop();
                }
                s.push(i);
            }
        }
    }
    return ans;
}

int main(){ 
    long long arr[5] = {6,8,0,1,3};
    vector<long long> ans = nextlargestElement(arr, 5);
    for (int i=0; i<5; i++){
        cout<<ans[i]<<" ";
    }
}