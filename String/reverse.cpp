#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    int x= 2437;
    int y = 875;
    int i=0;
    while (i<6 && x!=y){
        if (x<y){
            x = x-y;
        }
        else{
            y = y-x;
        }
        i++;
    }
    cout<<x<<" "<<y <<" "<<i;
}