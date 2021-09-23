#include <bits/stdc++.h>
using namespace std;

int findProfit(int arr[], int n){
    int ans;
    int profit[n];
    int maxPrice = arr[n-1];
    for (int i=0; i<n; i++){
        profit[i] =0;
    }
    for(int i=n-2; i>=0; i--){
        if(maxPrice < arr[i])
            maxPrice = arr[i];
        profit[i] = max(profit[i+1], maxPrice-arr[i]);
    }
    int minPrice = arr[0];
    for (int i=1; i<n; i++){
        if (arr[i]<minPrice){
            minPrice = arr[i];
        }
        profit[i] = max(profit[i-1], profit[i]+arr[i]-minPrice);
    }
    ans = profit[n-1];
    return ans;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<findProfit(arr, n)<<endl;

}