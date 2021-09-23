#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i=0; i<arr.size(); i++){
            if (arr[i] < minPrice){
                minPrice = arr[i];
            }else{
                if (arr[i]-minPrice > maxProfit){
                    maxProfit = arr[i]-minPrice;
                }
            }
        }
        return maxProfit;
    }
};
