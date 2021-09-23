#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<int> temp ;
        if (arr.size() == 0){
            return arr;
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        temp = arr[0];
        for (auto it: arr){
            if (temp[1] >= it[0]){
                temp[1] = max(it[1], temp[1]);
            }else{
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
