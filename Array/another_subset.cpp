#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string findSubset(vector<int> arr1, vector<int> arr2){
    unordered_map<int, bool> mpp;
        for(int i=0; i<arr1.size(); i++){
            mpp[arr1[i]] = true;
        }
        for (int i=0; i<arr2.size(); i++){
            if(mpp.find(arr2[i]) == mpp.end()){
                return "No";
            }
        }
        return "Yes";
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        vector<int> arr1, arr2;
        int x;
        for(int i=0; i<m; i++){
            cin>>x;
            arr1.push_back(x);
        }
        for(int i=0; i<n; i++){
            cin>>x;
            arr2.push_back(x);
        }
        cout<<findSubset(arr1, arr2);
    }
}