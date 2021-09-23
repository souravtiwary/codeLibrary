#include <bits/stdc++.h>
using namespace std;

int findGap(int gap){
    if(gap == 1){
        return 0;
    }
    return ceil(gap/2.0);
}

void mergeSortedArray(int *a, int *b, int sizea, int sizeb){
    int gap = sizea + sizeb;
    //cout<<"here";
    //gap = findGap(gap);
    while(true){
        gap = findGap(gap);
        if (gap == 0) return;
        //cout<<gap<<" ";
        if(gap == 0) break;;
        int i=0, j = gap;
        while(j < sizeb+sizea){
            cout<<i<<" "<<j<<endl;
            if(j < sizea){
                if(a[i] > a[j]){
                    swap(a[i], a[j]);
                }
            }
            else{
                if(i < sizea){
                    if(a[i] > b[sizea-j]){
                        swap(a[i], b[sizea-j]);
                    }
                }
                else{
                    if(b[sizea-i] > b[sizea-j]){
                        swap(b[sizea-i], b[sizea-j]);
                    }
                }
            }
            i++; j++;
        }
        
        
    }
}

int main(){
    int a[] = {2,5,9,11};
    int b[] = {1,3,6};
    mergeSortedArray(a, b, 4, 3);
    for(int i=0; i<4; i++){
        cout<<a[i]<<" ";
    }
    for(int i=0; i<3; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
} 