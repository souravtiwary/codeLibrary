#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	   long long min_sofar = arr[0], max_sofar = arr[0];
       long long max_final = arr[0];
       for(int i=1; i<n; i++){
           if(arr[i] < 0) swap(max_sofar, min_sofar);
           
           max_sofar = max((long long)arr[i], max_sofar*arr[i]);
           min_sofar = min((long long)arr[i], min_sofar*arr[i]);
           
           //max ans
           max_final = max(max_final, max_sofar);
       }
    
    return max_final;
	}
};

int main(){

}