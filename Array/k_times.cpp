#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    unordered_map<int, int> mpp;
    for (int i=0; i<n; i++){
        mpp[arr[i]] += 1;
    }
    int count=0;
    for (auto it: mpp){
        if (it.second > n/k){
            cout<<it.first<<"->>"<<it.second<<endl;
            count++;
        }
    }
    cout<<count;
}