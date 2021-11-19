#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[1001][1001];
bool vis[1001][1001];
int dist[1001][1001];

bool isValid(int x , int y ){
    if(x<1 || x>N ||y<1 || y>M) return false;
    if(vis[x][y]==true)return false;
    return true;
}
int dx[] = {2, 1, -1, -2, -2, -1, 1 ,2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

void BFS(int NodeX, int NodeY){
    queue<pair<int,int>> q;
    
    q.push({NodeX, NodeY});
    dist[NodeX][NodeY] = 0;
    vis[NodeX][NodeY] = true;

    while(!q.empty()){
        int currX = q.front().first; //X coordinate
        int currY = q.front().second; //Y coordinate
        q.pop();
        for(int i = 0; i<4 ;i++){
            if(isValid(currX + dx[i], currY + dy[i])==1){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                q.push({newX, newY});
                vis[newX][newY] = 1;
                dist[newX][newY] = dist[currX][currY] + 1 ;
                              
            }
        }
    }
}



int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

cin >> N >> M;

for(int i=1 ; i<=N ; i++){
    for(int j=1; j<=M ; j++){
        cin>>arr[i][j];
    }
}

BFS(1,1);

for(int i=1 ; i<=N ; i++){
    for(int j=1; j<=M ; j++){
        cout<<dist[i][j] << " ";
    }
    cout << endl;
}

return 0;
}