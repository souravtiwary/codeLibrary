#include<bits/stdc++.h>
using namespace std;

bool findExtra(string s)
{
    stack<char> st;
    int i=0;
    char top;
    while(i<s.length()){
        if (s[i] == ')'){
            top = st.top();
            st.pop();
            bool flag = true;
            while(top != '('){
                if (top == '*' || top == '/' || top == '+' || top == '-'){
                    flag = false;
                }
                top = st.top();
                st.pop();
            }
            if (flag){
                return true;
            }
        }
        else {
            st.push(s[i]);
            
        }
        i++;
    }

    return false;

}
int main(){
    string s;
    cin>>s;
    cout<<findExtra(s);
}