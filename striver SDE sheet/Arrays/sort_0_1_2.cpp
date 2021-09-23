#include <iostream>
using namespace std;

void sortArray(int *arr, int n){
    if(n == 1) return;
    int left = 0;
    int mid = 0, high = n-1;
    while(mid < high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[left]);
            left++;
            mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
        else{
            mid++;
        }
    }
}

int main(){
    //int *arr = new int[11];
    int arr[] = {1,1,1,1,1,1,0,0,0,0,2,2,2,2};
    sortArray(arr, 14);
    for(int i=0; i<14; i++){
        cout<<arr[i] <<" ";
    }
}