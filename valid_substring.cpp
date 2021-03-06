#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findMaxlenght(string s){
            stack<int>S;
            S.push(-1);
            int result=0;
            for(int i = 0 ; i < s.length() ; i++ ) {
                if(s[i]=='(') {
                S.push(i);
                }
                else {
                    S.pop();

                    if( !S.empty() ) {
                        result=max( result , i - S.top() ) ;
                    }
                    else{
                        S.push(i);
                    }
                }
            }
            return result;
        }
};

int main(){
    Solution obj;
    cout<<obj.findMaxlenght(")(()()");
}
