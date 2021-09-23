#include<bits/stdc++.h>
#include <vector>
using namespace std;

int findSwapsRequired(int arr[], int size){
    pair<int, int> holder[size];
    for (int i=0; i<size; i++){
        holder[i].first = arr[i];
        holder[i].second = i;
    }
    sort(holder, holder+size);

    vector<bool> visited(size, false);
    int ans = 0;
    for (int i =0; i<size; i++){
        if (visited[i] || holder[i].second == i){
            continue;
        }
        int cyc_size = 0;
        int j = i;
        while(!visited[j]){
            visited[j] = true;
            j = holder[j].second;
            cyc_size++;
        }

        if (cyc_size > 0){
            ans += (cyc_size-1);
        }

    }
    
    return ans;

}


int main() {
    int n;
    cin>>n;
    int arr[n];
    int ans = findSwapsRequired(arr, n);
    cout<<ans<<endl;
}