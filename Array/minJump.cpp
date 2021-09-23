#include<bits/stdc++.h>
using namespace std;


// Function to return minimum number of jumps to end of array
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(arr[0] == 0) return -1;
        if(n < 1) return 0;
        int jumps = 1;
        int reach = arr[0];
        int steps = arr[0];
        for(int i=1; i<n; i++){
            if(i == n-1) return jumps;
            reach = max(reach, i+arr[i]);
            steps --;
            if(steps == 0){
                jumps++;
                if(reach <= i) return -1;
                steps = reach - i;
            }
        }
        return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends