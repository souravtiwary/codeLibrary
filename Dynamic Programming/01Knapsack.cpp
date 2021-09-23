#include <bits/stdc++.h>
#include <cstring>
#include <iterator>
using namespace std;

void printGrid(vector<vector<int>> grid){
    for(int i=0; i<grid.size(); i++){
        for(int x:grid[i]) cout<<x<<" ";
        cout<<endl;
    }
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   vector<vector<int>> grid(n+1, vector<int>(W+1, 0)); // grid of price
   for(int row = 1; row <= n; row++){
       for(int col = 1; col <= W; col++){
           int currwt = wt[row-1];
           int price = val[row-1];
           if(currwt <= col){
               // max(price of curr wt + price of wt remaining, price if currwt is not selected)
               grid[row][col] = max(price + grid[row-1][col-currwt], grid[row-1][col]);
           } 
           else{
               grid[row][col] = grid[row-1][col];
           }
       }
   }
   return grid[n][W];

}

int main(){
    int n, w;
    cin>>n>>w;
    int weg[n] ;
    int val[n] ;
    for (int i=0; i<n; i++){
        cin>>val[i];
    }
    for (int i=0; i<n; i++){
        cin>>weg[i];
    }
    cout<<knapSack(w, weg, val, n);
}