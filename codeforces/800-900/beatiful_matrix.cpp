#include <bits/stdc++.h>
using namespace std;

int main(){
    //int arr[5][5];
    int ans;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int t;
            cin>>t;
            if(t == 1){
                ans = abs(2-i) + abs(2-j);
                break;
            }

        }
    }
    cout<<ans<<endl;
}
