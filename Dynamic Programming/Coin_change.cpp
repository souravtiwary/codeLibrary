#include <bits/stdc++.h>
using namespace std;

long long int count( int S[], int m, int n ){
    long long int ways[n+1];
    for (int i=0; i<=n; i++){
        ways[i] = 0;
    } 
    ways[0] = 1;
    sort(S, S+m);
    for (int i=0; i<m; i++){
        for (int j=1; j<= n; j++){
            if (S[i] <= j){
                ways[j] = ways[j] + ways[j-S[i]]; 
            }
        }
    }
    return ways[n];
}

int main(){
    int n, m;
    cin>>n>>m;
    int arr[m];
    for (int i=0; i<m; i++){
        cin>>arr[i];
    }
    cout<<count(arr, m, n);
}