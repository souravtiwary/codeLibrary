#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
void dfs(vector<int> list[], int node){
    visited[node] = true;
    cout<<node<<" ";
    for(int x: list[node]){
        if(!visited[x]) dfs(list, x);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> list[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    visited.resize(n+1, false);
    for(int i=1; i<=n; i++){
        cout<<i<<": ";
        for(int x: list[i]) cout<<x<<" ";
        cout<<"\n";
    }
    // pass list list and the node from which dfs should start
    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(list, i);
    }
}