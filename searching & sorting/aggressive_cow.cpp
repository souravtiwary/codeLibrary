#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n, c;
    cin>>n>>c;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int left=0, right = arr[n-1], mid = 0,gap=0, best = 0;
    while(left < right){
        mid = (left+right)/2;
        gap = mid - left;
        int l = 1; //to calculate gap
        int cnt = 1;
        for (int i=1; i<n && cnt<c; i++){
            if (arr[i] - l >= gap){
                l = arr[i];
                cnt++;
            }
        }
        if (cnt >= c){
            best = max(best, gap);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout<<best<<endl;
}