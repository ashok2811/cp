#include <bits/stdc++.h>
using namespace std;
int N,M;
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
        for(int i = 0; i<8 ;i++){
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
int t;
cin >> t;
N=M=8;
while(t--){
    for(int i= 1 ; i <=8; i++){
        for(int j = 1; j<=8; j++){
            dist[i][j] =0;
            vis[i][j] = 0;
        }
    }  
    string start, end;
    cin >> start >> end;
    int xi = start[0] -'a' +1 ;
    int yi = start[1] -'1' +1 ;
    int xf = end[0] -'a' +1 ;
    int yf = end[1] -'1' +1 ;
    BFS(xi , yi);
    cout << dist[xf][yf] <<endl;
    // for(int i= 1 ; i <=8; i++){
    //     for(int j = 1; j<=8; j++){
    //         cout << dist[i][j] <<":" <<vis[i][j] <<" ";
    //     }
    //     cout << endl;
    // }

}



return 0;
}