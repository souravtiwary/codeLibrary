#include<bits/stdc++.h>
using namespace std;

void findRepeatingAndMissing(int *arr, int n){
    int xxor = 0;
    for(int i=0; i<n; i++){
        xxor = xxor ^ arr[i];
    }
    for(int i=1; i<=n; i++){
        xxor ^= i;
    }
    int set_bit = xxor & ~(xxor-1);
    //cout<<set_bit;
    int x = 0;
    int y = 0;
    for(int i=0; i<n; i++){
        if(arr[i] & set_bit){
            x ^= arr[i];
        }
        else{
            y ^= arr[i];
        }
    }
    for(int i=1; i<=n; i++){
        if(i & set_bit){
            x ^= i;
        }
        else{
            y ^= i;
        }
    }
    cout<<x<<" "<<y<<endl;
    int missing = 0, repeating = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == x || arr[i]==y){
            repeating = arr[i];
            missing = arr[i] == x ? y : x;
            break;
        }
    }
    cout<<repeating<<" "<<missing<<endl;
}

int main(){
    int n;
    //cin>>n;
    n = 6;
    //int *arr = new int[n];
    int arr[] = {1,6,2,3,5,5};
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    findRepeatingAndMissing(arr, n);
    return 0;


    int repeating, missing;
    for(int i=0; i<n; i++){
        if(arr[abs(arr[i]) - 1] > 0){
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
        else{
            repeating = abs(arr[i]);
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            missing = i+1;
        }
    }
    cout<<repeating<<" "<<missing<<endl;

    //delete [] arr;
    return 0;
}