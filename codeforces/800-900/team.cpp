#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i=0; i<n; i++){
        int cnt = 0; // people know
        for(int j=0; j<3; j++){
            int t;
            cin>>t;
            if(t == 1){
                cnt++;
            }
        }
        //cout<<cnt<<endl;
        if(cnt >= 2){
            ans++;
        }
    }
    cout<<ans<<endl;
}