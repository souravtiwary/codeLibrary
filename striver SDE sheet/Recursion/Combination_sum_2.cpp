#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(int idx, vector<int> arr, int t, vector<int> &ds, vector<vector<int>> &ans){
        if(idx == arr.size()){
            if(t == 0){
                ans.push_back(ds);
            }
            return;
        }
        for(int i=idx; i<arr.size(); i++){
            if(i > idx && arr[i] == arr[i-1]) continue;
            if(t <= arr[i]){
                ds.push_back(arr[i]);
                helper(i+1, arr, t, ds, ans);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, target, ds, ans);
        return  ans;
    }

};