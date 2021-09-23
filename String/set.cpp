#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

int val[11000];
int n=0;
int cnt=0;

void primeFactor(int x, vector<vector<int>> &vec){
    vector<int> pri;
    int a[10] = {2,3,5,7,11,13,17,19,23,29};
    for(auto i:a){
        if(x%i == 0){
            if(x%(i*i) == 0) return;
            pri.push_back(i);
        }
    }
    vec.push_back(pri);
    val[n] = x;
    n++;
}

void solve(int i, vector<int> emp, vector<vector<int>> vec){
    vector<int> uni;
    //set_union(emp.begin(), emp.end(), vec[i].begin(), vec[i].end(), uni.begin());
    unordered_map<int, bool> mpp;
    for(int i=0; i<emp.size(); i++){
        mpp[emp[i]] = true;
        uni.push_back(emp[i]);
    }
    for(int k : vec[i]){
        if(mpp.find(k) == mpp.end()) uni.push_back(k);
    }
    if(uni.size() != (emp.size() + vec[i].size())) return;
    cnt++;

    for(int j=i+1; j<n; j++){
        solve(j, uni, vec);
    }
}

int main(){
    int t;
    cin>>t;
    while (t--) {
        cnt = 0;
        n = 0;
        int temp;
        cin>>temp;
        int arr[temp];
        for(int i=0; i<temp; i++){
            cin>>arr[i];
        }
        vector<vector<int>> vec;
        for(int i=0; i<temp; i++){
            primeFactor(arr[i], vec);
        }
        for(int i=0; i<n; i++){
            vector<int> emp;
            solve(i, emp, vec);
        }
        cout<<cnt<<"\n";
    }
    
}