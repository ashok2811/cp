#include <bits/stdc++.h>
using namespace std;
int N,M;
char arr[1001][1001];
bool vis[1001][1001];

bool isValid(int x , int y ){
    if(x<1 || x>N ||y<1 || y>M) return false;
    if(vis[x][y]==true || arr[x][y] =='#')return false;
    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){ // dfs on 2D grid
    vis[x][y]= true;
    //cout <<x << " " << y << endl;
    for (int i=0; i< 4 ; i++)
    if(isValid(x +dx[i], y +dy[i])){
        dfs(x +dx[i], y +dy[i]);
    }
    
}


int main(){

// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif


cin >> N >> M;

for(int i=1 ; i<=N ; i++){
    for(int j=1; j<=M ; j++){
        cin>>arr[i][j];
    }
}

int cc = 0 ;
for (int i = 1; i <=N; i++){ // Checking for connected components
    for (int j = 1; j<=M; j++){
        if(vis[i][j] ==0 && arr[i][j] == '.'){
        cc++;
        dfs(i,j);
        }
    }
    
}
cout<<cc << endl;
return 0;
}