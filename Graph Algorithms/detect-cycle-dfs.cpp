#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<bool> vis;

bool detect_cycle_dfs(vector<int> list[], int node, int par){
    //if(vis[node]) return true;
    vis[node] = true;
    for(int x: list[node]){
        if(!vis[x]) {
            if(detect_cycle_dfs(list, x, node)) return true;
        }
        else if (x != par) return true;
    }
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    vis.resize(n+1, false);
    vector<int> list[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(detect_cycle_dfs(list, i, -1)){
                cout<<"Cycle Found\n";
                break;
            }
        }
    }
}