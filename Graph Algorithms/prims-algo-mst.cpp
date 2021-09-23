#include <bits/stdc++.h>
using namespace std;

// mst have n nodes and n-1 edges

int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> list[n];
    for(int i=0; i<m; i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        list[a].push_back(make_pair(b,wt));
        list[b].push_back(make_pair(a,wt));
    }
    //============Brute force===============
    // int parent[n];
    // int key[n];
    // bool mstSet[n];

    // for(int i=0; i<n; i++)
    //     key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    // key[0] = 0;
    // parent[0] = -1;

    // for(int count = 0; count<n-1; count++){
    //     int mini = INT_MAX, nodeIdx;

    //     // finding mini takes O(N) time so instead we can use priority queue
    //     for(int it=0; it<n; it++){
    //         if(!mstSet[it] && mini < key[it])
    //             mini = key[it], nodeIdx = it;
    //     }

    //     mstSet[nodeIdx] = true;

    //     for(auto x : list[nodeIdx]){
    //         int node = x.first;
    //         int weight = x.second;
    //         if(mstSet[node] == false && weight < key[node])
    //             parent[node] = nodeIdx, key[node] = weight;
    //     }
    // }

    //==============Efficeint===============
    int parent[n]; // parent of node
    int key[n]; // min weight to reach 
    bool mstSet[n]; // to check if node is in mst

    for(int i=0; i<n; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0}); // weight, idx;

    for(int count = 0; count<n-1; count++){
        int nodeIdx = pq.top().second;
        pq.pop();

        mstSet[nodeIdx] = true;

        for(auto x : list[nodeIdx]){
            int v = x.first;
            int weight = x.second;
            if(mstSet[v] == false && weight < key[v]){
                parent[v] = nodeIdx;
                pq.push({key[v], v});
                key[v] = weight;
            }
        }
    }


}