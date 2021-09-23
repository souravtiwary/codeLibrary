#include<bits/stdc++.h>
#include <vector>
using namespace std;

// using graph indegre and outdegree
int celebrity(vector<vector<int>> &M, int n){
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int x = M[i][j];
            outdegree[i] += x;
            indegree[j] += x;
        }
    }

    for (int i =0; i<n; i++){
        if (indegree[i] == n-1 && outdegree[i] == 0){
            return i;
        }
    }
    return -1;
}

int celebrityUsingStack(vector<vector<int>> &M, int n){
    stack <int> s;
    for (int i=0; i<n; i++){
        s.push(i);
    }
    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();
    while(s.size() > 1){
        if (M[A][B]){
            A = s.top();
            s.pop();
        }
        else{
            B = s.top();
            s.pop();
        }
    }

    if (s.empty()){
        return -1;
    }
    int C = s.top();
    if (M[C][B]){
        C = B;
    }
    if (M[C][A]){
        C = A;
    }
    for (int i=0; i<n; i++){
        if (i != C){
            if (M[C][i] == 1 || !M[i][C]){
                return -1;
            }
        }
    }
    return C ? C : -1;
}

int celebrityUsingTwoPointer(vector<vector<int>> &M, int n){
    int a =0;
    int b = n-1;
    while(a<b){
        if (M[a][b]){
            a++;
        }
        else{
            b--;
        }
    }
    for (int i=0; i<n; i++){
        if ((i != a) && (M[a][i] || !M[i][a])){
            return -1;
        }
    }
    return a;
}

int main(){
    vector<vector<int>> M = {{0,1,0},{1,0,0},{0,0,1}};
    cout<<celebrityUsingStack(M, 3)<<endl;
    return 0;
}