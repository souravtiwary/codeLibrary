#include <bits/stdc++.h>
using namespace std;

vector<int> dist;
vector<int> visited;

void calculateDist(vector<pair<int,int>> list[], int n, stack<int> &s){
    int curr = s.top();
    dist[curr] = 0;
    while (!s.empty()) {
        curr = s.top();
        s.pop();
        if(dist[curr] != INT_MAX){
            for(auto x : list[curr]){
                if(dist[x.first] > (dist[curr] + x.second)){
                    dist[x.first] = dist[curr] + x.second;
                }
            }
        }
    }
}

void topoDFS(vector<pair<int, int>> list[], int node, stack<int> &s){
    if(visited[node]) return;
    visited[node] = 1;
    for(auto x: list[node]){
        if(!visited[x.first]){
            topoDFS(list, x.first, s);
        }
    }
    s.push(node);
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> list[n];
    dist.resize(n, INT_MAX);
    visited.resize(n, 0);
    stack<int> s;
    for(int i=0; i<n; i++){
        if(!visited[i]) topoDFS(list, i, s);
    }
    calculateDist(list, n, s);
    for(int x: dist) cout<<x<<" ";
    cout<<"\n";
    
}
