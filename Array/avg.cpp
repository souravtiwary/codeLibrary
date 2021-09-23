#include <bits/stdc++.h>
using namespace std;

int findAverage(vector<int> array, int size){
    int lengthOfSubset = 0, numberOfSubset = 0, tempLength = 0;
    int it=0;
    bool startSingle = false;
    while(it < size){
        int num = 10 - array[it];
        if(num < 10 && num > 0){
            startSingle = true;
            tempLength++;
        }
        else {
            if(startSingle){
                startSingle = false;
                lengthOfSubset+= tempLength;
                tempLength=0;
                numberOfSubset++;
            }
        }
        it++;
    }
    // if last is single length
    if(startSingle){
        lengthOfSubset += tempLength;
        numberOfSubset++;
    }
    return (lengthOfSubset/numberOfSubset);
}

int main(){
    vector<int> arr;
    while (true) {
        int x;
        cin>>x;
        if(x < 0) break;
        arr.push_back(x);
    }
    int n = arr.size();
    cout<<findAverage(arr, n);
}