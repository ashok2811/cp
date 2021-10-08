#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[1001][1001];
bool vis[1001][1001];

bool isValid(int x , int y ){
    if(x<1 || x>N ||y<1 || y>M) return false;
    if(vis[x][y]==true)return false;
    return true;
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



return 0;
}