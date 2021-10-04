#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[100001];

void dfs(int node, int & length){
    vis[node] = 1;
    length++;
    for(auto child :adj[node]){
        if(!vis[child]){
            dfs(child , length);
        }
    }
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int T; cin >> T;
while(T--){

int V , E , u, v;
cin>>V>>E;

for(int i = 1 ; i<=V; i++){
    adj[i].clear();
    vis[i] = 0 ;
}

while(E--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int cc= 0 ;
int MOD = 1000000000 + 7;
long long ans = 1 ;
for (int i = 1; i <=V; i++)
{
    if(!vis[i]){
        cc++;
        int length = 0;
        dfs(i , length );
       //cout << length << " ";
       ans = (ans*(long long)length)%(long long)(1e9 + 7);
    }
}

cout <<cc <<" "<< ans <<endl;
}
return 0;
}