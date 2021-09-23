#include <bits/stdc++.h>
using namespace std;

// void swap(int *i, int *j){
//     cout<<*i<<" "<<*j<<endl;
//     int *temp = i;
//     *i = *j;
//     *j = *temp;
// }

void mergeSortedArray(int arr1[], int arr2[], int n, int m){
    int i = 0;
    int j = 0;
    while(i < n){
        if(arr1[i] > arr2[j]){
            swap(arr1[i], arr2[j]);
            while (j < m-1) {
                if(arr2[j] > arr2[j+1]){
                    swap(arr2[j], arr2[j+1]);
                    j++;
                }
                else{
                    break;
                }
                
            }
            j = 0;
        }i++;
    }
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<m; i++){
        cout<<arr2[i]<<" ";
    }
}

int main(){
    int n=7, m=6;
    int arr1[] = {2,3,6,9,10,19,22};
    int arr2[] = {2,3,5,6,7,9};
    mergeSortedArray(arr1, arr2, n, m);
    
}