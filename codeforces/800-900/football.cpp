#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int zero = 0;
    int one = 0;
    //s[0] == '0' ? zero++ : one++;
    string ans = "NO";
    for(int i=0; i<s.length(); i++){
        if(s[i] == '0'){
            one = 0;
            zero ++;
        }
        else{
            zero = 0;
            one++;
        }
        if(one == 7 || zero == 7){
            ans = "YES";
        }
    }
    cout<<ans<<endl;
}