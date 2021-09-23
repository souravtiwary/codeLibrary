#include <bits/stdc++.h>
using namespace std;

int findTriplet(int arr[], int n, int target){
    unordered_map<int, int> mpp;
    int l, r;
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        l = i+1;
        r = n-1;
        while(l < r){
            if (arr[i]+arr[l]+arr[r] == target){
                return 1;
            }
            else if (arr[i]+arr[l]+arr[r] < target) {
                l++;
            }else{
                r--;
            }
        }
    }
    return 0;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, x;
        cin>>n>>x;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<findTriplet(arr, n, x);
    }
}