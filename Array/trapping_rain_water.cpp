#include <bits/stdc++.h>
using namespace std;

int findAmount(int arr[], int n){
    int ans=0;
    int size = min(arr[0], arr[n-1]);
    for(int i=1; i<n-1; i++){
        if(size-arr[i]>=0){
            ans += size- arr[i];
        }
        else{
            size = arr[i];
        }
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<findAmount(arr, n)<<endl;
    }
}