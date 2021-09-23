#include <cstdint>
#include <iostream>
#include <cstring>
using namespace std;

void findPalindrom(string s){
    int arr[s.size()][s.size()];
    memset(arr, 0, sizeof(arr));
    int start{}, maxsize{};
    for (int i=0; i<s.size(); i++){
        arr[i][i] = 1;
        maxsize = 1;
    }
    for (int i=0; i<s.size()-1; i++){
        if(s[i] == s[i+1]){
            arr[i][i+1] = 1;
            maxsize = 2;
            start = i;
        }
    }
    for (int k=3; k<s.size(); ++k){
        for(int i=0; i<s.size()-k+1; ++i){
            int j = i + k -1;
            if (arr[i+1][j-1] == 1 && s[i] == s[j]){
                arr[i][j] = 1;
                if (k > maxsize){
                    start = i;
                    maxsize = k;
                }
            }
        }
    }
    
    for (int x=start; x<=start+maxsize-1;x++){
        cout<<s[x];
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        findPalindrom(s);
    }
}