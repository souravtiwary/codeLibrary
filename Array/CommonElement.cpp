#include<bits/stdc++.h>
using namespace std;

// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays

class Solution{
    public:

        vector<int> findCommon(int A[], int B[], int C[], int n1, int n2, int n3){
            vector <int> ans;
            int i =0, j=0, k=0;
            while(i<n1 && j<n2 &&k<n3){
                if (A[i] == B[j] && B[j]==C[k]){
                    ans.push_back(A[i]);
                    i++; j++; k++;
                }
                if (A[i] < B[j]){
                    i++;
                }
                if (B[j] < C[k]){
                    j++;
                }
                else{
                    k++;
                }
            }
            return ans;
        }           
};

int main(){

}