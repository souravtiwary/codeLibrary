#include <bits/stdc++.h>
#include <string>
using namespace std;

bool ispar(string x){
    stack<char> sta;
    for (int i =0; i<x.length(); i++){
        char currentSymbol = (char)x[i];
        if (currentSymbol == '{' || currentSymbol == '[' || currentSymbol == '('){
            sta.push(currentSymbol);
        }
        else{
            if (currentSymbol == '}'){
                if (!sta.empty()){
                    if (sta.top() == '{'){
                        sta.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else if (currentSymbol == ']'){
                if (!sta.empty()){
                    if (sta.top() == '['){
                        sta.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                if (!sta.empty()){
                    if (sta.top() == '('){
                        sta.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
    }
    if (sta.empty()){
        return true;
    }
    return false;
}

int main(){
    string s;
    getline(cin , s);
    if (ispar(s)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}