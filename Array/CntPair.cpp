#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int getPairCount(int arr[], int n, int k){
            int count = 0;
            int temp;
            unordered_map<int, int> mp;
            for (int i=0; i<n; i++){
                mp[arr[i]] += 1;
            }
            
            for (int i=0; i<n; i++){
                int temp = k - arr[i];
                if (mp.find(temp) != mp.end()){
                    count += mp[temp];
                    mp[arr[i]]--;

                    if (arr[i] == temp) {count--;}
                }
                
            }
            return count;
        }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for (int i =0; i<n; i++){
            cin>>arr[i];
        }
        int k;
        cin>>k;
        Solution obj;
        int ans = obj.getPairCount( arr,  n, k);
        cout<<"ans: "<< ans<<endl;
    }
    
    
}