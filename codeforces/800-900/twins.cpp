#include <algorithm>
#include<bits/stdc++.h>
#include <functional>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sumofArr = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i=0; i<n; i++){
        sumofArr += arr[i];
    }
    int ourSum = 0;
    int i=0;
    for(; i<n; i++){
        ourSum += arr[i];
        sumofArr -= arr[i];
        if(ourSum > sumofArr){
            break;
        }
    }
    cout<<i+1<<endl;
}