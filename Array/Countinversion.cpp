#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int mergeArr (ll arr[], ll temp[], ll left, ll mid, ll right){
    ll i, j, k;
    i = left;
    j = mid;
    k = left;
    int inversion_Cnt = 0;

    while(i<=mid-1 && j<=right){
        if (arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            inversion_Cnt += (mid-i);
        }
    }
    while(i<=mid-1){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for (ll i=0; i<=right; i++){
        arr[i] = temp[i];
    }
    return inversion_Cnt;
}

int _mergeSort(ll arr[], ll temp[], ll left, ll right){
    int inversion_Cnt = 0;
    if (left < right){
        ll mid = (left+right) / 2;
        inversion_Cnt += _mergeSort(arr, temp, left, mid);
        inversion_Cnt += _mergeSort(arr, temp, mid+1, right);
        inversion_Cnt += mergeArr(arr, temp, left, mid+1, right);
    }

    return inversion_Cnt;
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n], temp[n];
        for (ll i=0;i <n; i++){
            cin>>arr[i];
        }
        ll ans = _mergeSort(arr, temp, 0, n-1);
        cout<<ans<<endl;
    }
}
