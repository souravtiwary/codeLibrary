#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<bool> visited;

bool detect_cycle_bfs_directed(vector<int> list[], int node, int n){
    vector<int> indegre(n+1, 0);

    // calculate indegre
    for(int i=1; i<=n; i++){
        for(int x : list[i]) indegre[x]++;
    }

    queue<int> q;

    for(int i=1; i<=n; i++){
        if(indegre[i] == 0) q.push(i);
    }
    // Initialize count of visited vertices
    int cnt = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for(int x : list[node]){
            indegre[x]--;
            if(indegre[x] == 0) q.push(x);
        }
        cnt++;
    }
    // Check if there was a cycle
    if(cnt == n){
        // all node are visited and topo is successful
        return false;
    }
    return true;
}

int main(){
    int n , m;
    cin>>n>>m;
    vector<int> list[n+1];
    visited.resize(n, false);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        list[u].push_back(v);
    }
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            if(detect_cycle_bfs_directed(list, i, n)){
                cout<<"Found "<<i<<"\n";
            }
        }
    }
}