#include <bits/stdc++.h>
using namespace std;
int N,M;
char arr[1001][1001];
bool vis[1001][1001];
int dist[1001][1001];

bool isValid(int x , int y ){
    if(x<1 || x>N ||y<1 || y>M) return false;
    if(vis[x][y]==true || arr[x][y]=='T') return false;
    return true;
}
int dx[] = {-1 ,0, 1, 0};
int dy[] = {0, 1 , 0,-1};

void BFS(int NodeX, int NodeY){
    queue<pair<int,int>> q;
    
    q.push({NodeX, NodeY});
    vis[NodeX][NodeY] = true;
    dist[NodeX][NodeY] = 0 ;

    while(!q.empty()) {
        int currX = q.front().first; //X coordinate
        int currY = q.front().second; //Y coordinate        
        q.pop();
        for(int i = 0; i<4 ;i++){
            if(isValid(currX + dx[i], currY + dy[i])==1){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                q.push({newX, newY});
                vis[newX][newY] = 1;
                dist[newX][newY]= 1 + dist[currX][currY];
            }
        }
    }
}



int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

cin >> N;
M = N;
pair<int, int> start;
pair<int, int> end;
for(int i=1 ; i<=N ; i++){
    for(int j=1; j<=M ; j++){
        cin>>arr[i][j];
        if(arr[i][j]=='S'){
            start.first = i;
            start.second = j;
        }
        if(arr[i][j]=='E'){
            end.first = i;
            end.second = j;
        }
    }
}

BFS(start.first , start.second);

cout <<dist[end.first][end.second] - dist[start.first][start.second] <<endl;

return 0;
}