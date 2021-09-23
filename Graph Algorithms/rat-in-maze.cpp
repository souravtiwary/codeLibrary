#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> maze, vector<vector<int>> visited, int i, int j, int n){
    if(i < 0 || j < 0 || i >= n || j >= n || visited[i][j] == 1 || maze[i][j] == 0) return false;
    return true;
}

void mazeHelp(vector<vector<int>> maze, vector<vector<int>> visited,vector<string> &possiblePaths,  string &path,  int n, int i, int j){
    
    if(i < 0 || j < 0 || i>=n || j >= n || maze[i][j] == 0 || visited[i][j] == 1) {
        return;
    }
    
    if(i == n-1 && j == n-1){
        possiblePaths.push_back(path);
        //cout<<"Inside";
        return;
    }

    

    visited[i][j] = 1;
    if(isSafe(maze, visited, i+1, j, n)){
        path.push_back('D');
        mazeHelp(maze, visited, possiblePaths, path, n, i+1, j);
        path.pop_back();
    }
    if(isSafe(maze, visited, i, j-1, n)){
        path.push_back('L');
        mazeHelp(maze, visited, possiblePaths, path, n, i, j-1);
        path.pop_back();
    }
    if(isSafe(maze, visited, i, j+1, n)){
        path.push_back('R');
        mazeHelp(maze, visited, possiblePaths, path, n, i, j+1);
        path.pop_back();
    }
    if(isSafe(maze, visited, i-1, j, n)){
        path.push_back('U');
        mazeHelp(maze, visited, possiblePaths, path, n, i-1, j);
        path.pop_back();
    }
    visited[i][j] = 0;
}

void ratInMaze(vector<vector<int>> maze, int n){
    string path ;
    vector<string> possiblePaths;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    mazeHelp(maze, visited, possiblePaths, path, n, 0, 0);
    //cout<<" "<<possiblePaths.size();
    for(string x : possiblePaths){
        cout<<x<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> maze(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>maze[i][j];
    }
    ratInMaze(maze, n);   
}