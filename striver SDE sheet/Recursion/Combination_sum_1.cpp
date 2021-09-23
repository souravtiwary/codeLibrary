#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:

    void helper(int idx, vector<int> can, int t, vector<vector<int>> &ans, vector<int> &ds){
        if(idx == can.size()){
            if(t == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(can[idx] <= t){
            ds.push_back(can[idx]);
            helper(idx, can, t-can[idx], ans, ds);
            ds.pop_back();
        }
        helper(idx+1, can, t, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, candidates, target, ans, ds);
        return ans;
    }
};