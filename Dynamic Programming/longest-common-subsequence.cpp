#include <bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int>> grid){
    for(int i=0; i<grid.size(); i++){
        for(int x:grid[i]) cout<<x<<" ";
        cout<<endl;
    }
}

int longestCommonSubsequece(string a, string b){
    int n = a.length();
    int m = b.length();
    cout<<m<<" "<<n<<endl;
    vector<vector<int>> grid(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(b[i-1] == a[j-1])
                grid[i][j] = 1+grid[i-1][j-1];
            else
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
        }
    }
    printGrid(grid);
    return grid[m][n];
}

int main(){
    string a, b;
    cin>>a>>b;
    if(a.length() < b.length()){
        string temp = a;
        a = b;
        b = temp;
    }
    cout<<longestCommonSubsequece(a, b)<<endl;
}