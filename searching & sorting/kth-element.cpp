#include <bits/stdc++.h>
using namespace std;

int findPosition(int arr1[], int arr2[], int s1, int s2, int target){
    int temp=0;
    int i=0, j=0;
    while(i < s1 && j < s2){
        if (arr1[i] < arr2[j] ){
            temp++;
            if (temp == target){
                return arr1[i];
            }
            i++;
        }
        else{
            temp++;
            if (temp == target){
                return arr2[j];
            }
            j++;
        }
        
    }
    while(i < s1){
        temp ++;
        if (temp == target){
            return arr1[i];
        }
        i++;
    }

    while(j < s2){
        temp ++;
        if (temp == target){
            return arr2[j];
        }
        j++;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, target;
        cin>>n>>m>>target;
        int arr1[n];
        int arr2[m];
        for (int i=0; i<n; i++){
            cin>>arr1[i];
        }
        for (int i=0; i<m; i++){
            cin>>arr2[i];
        }

        cout<<findPosition(arr1, arr2,n,m, target)<<endl;
    }
}