#include <bits/stdc++.h>
using namespace std;
vector<int> adj[101];

int vis[101], low[101], in[101];
int timer = 0;

void dfs(int node, int parent){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    for(auto child :adj[node]){
        if(child == parent) continue;
        else if(vis[child]){
            // Back-Edge
            //cout<< child<<" "<< node << " Back-Edge" << endl;
            low[node] = min(low[node], in[child]);
        }
        else{
            dfs(child,node);
            if(low[child] > in[node]){
                cout << node << " - " << child << " is a bridge" << endl;
            }
            low[node] = min(low[node], low[child]);
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

dfs(1 ,-1);


return 0;
}