#include <bits/stdc++.h>
using namespace std;

// stack is used

vector<int> visited;
stack<int> s;

void topologicalSortUsingDFS(vector<int> list[], int n, int node){
    visited[node] = 1;
    for(int it : list[node]){
        if(!visited[it])
            topologicalSortUsingDFS(list, n, it);
    } 
    s.push(node);
}

int main(){
    int n, m;
    cin>>n>>m;
    visited.resize(n, 0);
    vector<int> list[n+1];
    vector<int> topo;
    for(int i=0; i<n; i++){
        if(!visited[i]) topologicalSortUsingDFS(list, n, i);
    }
    while (!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}