#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[100001];

void dfs(int node){
    vis[node] = 1;
    for(auto child :adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int V , E , u, v;
cin>>V>>E;

while(E--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

for (int i = 1; i <=V; i++)
{
    if(!vis[i]){
        dfs(i);
    }
}


return 0;
}