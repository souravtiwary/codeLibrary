#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n)
{
  //Your code here
  int temp[100001];
  for (int i=0; i<100001; i++){
      temp[i] =0;
  }
  int start = INT_MAX;
  for (int i=0;i<n;i++){
      temp[arr[i]] = 1;
      if (arr[i] < start){
          start = arr[i];
      }
  }
  int count = 0;
  int x = 0;
    while(start<100001){
        if (temp[start] == 1){
            x++;
        }else{
            count = max(x,count);
            x=0;
        }
        start++;
    }
  return max(x,count);
  
}