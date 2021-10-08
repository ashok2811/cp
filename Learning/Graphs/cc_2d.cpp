#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[1001][1001];
bool vis[1001][1001];

bool isValid(int x , int y ){
    if(x<1 || x>N ||y<1 || y>M) return false;
    if(vis[x][y]==true || arr[x][y] ==0)return false;
    return true;
}

void BFS(int nodeX, int nodeY){
    
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

int cc = 0 ;
for (int i = 1; i <=N; i++){ // Checking for connected components
    for (int j = 1; j<=M; j++){
        if(vis[i][j] ==0 && arr[i][j] == 1){
        cc++;
        dfs(i,j);
        }
    }
    
}
cout<<cc << endl;
return 0;
}