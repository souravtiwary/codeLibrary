// detect cycle using bfs traversal that use a queue that store current and parent
// node pair

#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;

bool detect_cycle(vector<int> list[], int node){
    queue<pair<int, int>> q;
    q.push(make_pair(node, -1));
    vis[node] = true;
    while(!q.empty()){
        pair<int, int> p = q.front(); //node, parent
        q.pop();
        //cout<<p.first<<" ";
        for(int x: list[p.first]){
            //cout<<x<<" ";
            if(x==p.second) continue;
            if(vis[x]) return true;
            else {
                vis[x] = true;
                q.push(make_pair(x, p.first));
            }
        }
    }
    return false;
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
    vis.resize(n+1, false);
    // for(int i=1; i<n; i++){
    //     for(int x: list[i]) cout<<x<<" ";
    //     cout<<"\n";
    // }
    // cout<<"\n";
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(detect_cycle(list, i)){
                cout<<"Cycle Found\n";
                break;
            }
        }
    }
    //cout<<ditect_cycle(list, 1);
}