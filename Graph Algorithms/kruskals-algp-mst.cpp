#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node{
    int u;
    int v;
    int wt;
    Node(int a, int b, int c){
        u = a;
        v = b;
        wt = c;
    }
};

int findParent(int node, vector<int> &parent){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionn(int u, int v, vector<int> &rank, vector<int> &parent){
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

bool comp(Node a, Node b){
    return a.wt < b.wt;
}

int main(){
    int n, m;
    //cin>>n>>m;
    vector<Node> list;
    list.resize(n);
    for(int i=0; i<m; i++){
        int u, v, wt;
        list[i] = Node(u, v, wt);
    }

    sort(list.begin(), list.end(), comp);

    vector<int> parent(n, 0);
    for(int i=0; i<n; i++) 
        parent[i] = i;

    vector<int> rank(n, 0);

    vector<pair<int,int>> mst;
    int cost = 0;

    for(auto it : list){
        if(findParent(it.u, parent) != findParent(it.v, parent)){
            cost += it.wt;
            unionn(it.u, it.v, rank, parent);
            mst.push_back({it.u, it.v});
        }
    }
    for(auto it: mst){
        cout<<it.first<<"->"<<it.second<<"\n";
    }
    cout<<cost<<"\n";

}