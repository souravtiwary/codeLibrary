#include <bits/stdc++.h>
using namespace std;
#define ll long long
// wrong ans
int main(){
    ll n, k;
    cin>>n>>k;
    ll even = n/2;
    ll odd = n - even;
    ll i;
    if(k < odd){
        i = 1;
        
        while(--k){
            i += 2;
        }
    }
    else{
        k = k - odd;
        i = 0;
        while(k--){
            i += 2;
        }
    }
    cout<<i<<endl;
}