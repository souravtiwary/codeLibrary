#include <bits/stdc++.h>
using namespace std;

string sumIsZero(int arr[], int n){
    unordered_map<int, int> mpp;
    if (n == 0){
        return "No";
    }
    int sum = 0 ;
    for(int i=0; i<n; i++){
        if (arr[i] == 0){
            return "Yes";
        }
        else{
            sum += arr[i];
            if (mpp.find(sum) != mpp.end() || sum == 0){
                return "Yes";
            }else{
                mpp[sum] = 1;
            }
        }
    }
    return "No";
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
        string ans = sumIsZero(arr, n);
        cout<<ans<<endl;
    }
}