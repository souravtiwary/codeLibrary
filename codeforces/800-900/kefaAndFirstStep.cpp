#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int maxAns = 1;
    int cont = 1;
    for(int i=1; i<n; i++){
        if(arr[i] >= arr[i-1]){
            cont++;
        }
        else{
            maxAns = max(maxAns, cont);
            cont = 1;
        }
    }
    maxAns = max(cont, maxAns);
    cout<<maxAns<<endl;
}