#include <bits/stdc++.h>
using namespace std;

// wrong ans

void printGrid(vector<vector<int>> grid, int n){
    for(int i=0; i<n; i++){
        for(int x : grid[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}

int checkPali(int start, int end, vector<vector<int>> grid){
    while (start < end) {
        if(grid[start++][end--] == 0) return 0;
    }
    return 1;
}

int longestPalindromeSize(string s, int n){
    int ans = 0;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        grid[i][i] = 1;
        if(i+1 < n && s[i] == s[i+1]) grid[i][i+1] = 1; 
    }
    int j = 2;
    int idx = 0;
    while(j < n){
        for(int i=0; i<n-j; i++){
            //cout<<i<<" "<<i+j<<endl;
            if(s[i] == s[i+j] && checkPali(i+1, i+j-1, grid)){
                grid[i][i+j] = 1;
                if(ans < j+2){
                    idx = i;
                    ans = j+2;
                }
            }
        }
        j++;
    }
    //cout<<idx;
    printGrid(grid, n);
    return ans;
}

int main(){
    cout<<longestPalindromeSize("aaaabbaa", 8);
}