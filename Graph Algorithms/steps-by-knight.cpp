#include <bits/stdc++.h>
using namespace std;

struct cell{
    int x;
    int y;
    int dis;
    cell(){};
    cell(int x, int y, int dis){
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};

bool insideGrid(int x, int y, int n){
    if(x >= 1 && y >= 1 && x <= n && y<= n) return true;
    return false;
}

int findSteps(int n, int start[], int target[]){
    bool visited[n+1][n+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            visited[i][j] = false;
        }
    }
    int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

    queue<cell> q;

    q.push(cell(start[0], start[1], 0));

    cell t;
    int x, y;

    visited[start[0]][start[1]] = true;

    while (!q.empty()) {
        t = q.front();
        q.pop();

        if(t.x == target[0] && t.y == target[1]) return t.dis;

        for(int i=0; i<8; i++){
            x = t.x + dx[i];
            y = t.y + dy[i];

            if(insideGrid(x, y, n) && !visited[x][y]){
                visited[x][y] = true;
                q.push(cell(x, y, t.dis+1));
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int initialpos[2];
    cin>>initialpos[0]>>initialpos[1];
    int finalpos[2];
    cin>>finalpos[0]>>finalpos[1];
    cout<<findSteps(n, initialpos, finalpos);
}