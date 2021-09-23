#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s.length() <= 10){
            cout<<s<<endl;
        }
        else{
            int k = s.length();
            cout<<s[0]<<k-2<<s[k-1]<<endl;
        }
    }
    return 0;
}