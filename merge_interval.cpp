#include <bits/stdc++.h>
#include <cwchar>
#include <vector>
using namespace std;

struct Interval{
    int start;
    int end;
};

bool comparision(Interval a, Interval b){
    return a.start < b.start;
}

stack<Interval> mergeInterval(Interval arr[], int n){
    stack<Interval> s;
    if (n < 1){
        return s;
    }
    if (n == 1){
        s.push(arr[0]);
        return s;
    }
    vector<vector<int>> ans;
    sort(arr, arr+n, comparision);
    s.push(arr[0]);
    for (int i=1; i<n; i++){
        Interval top = s.top();
        if (top.end < arr[i].start){
            s.push(arr[i]);
        }
        else if (top.end < arr[i].end){
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    return s;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Interval arr[n];
        for (int i=0; i<n; i++){
            int a, b;
            cin>>a>>b;
            arr[i].start = a;
            arr[i].end = b;
        }
        stack<Interval> s = mergeInterval(arr, n);
        while(!s.empty()){
            Interval top = s.top();
            cout<<top.start<<" "<<top.end<<endl;
            s.pop();
        }
    }

}