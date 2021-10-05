#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
vector<int> vis;
vector<int> dist;

void bfs(int node){
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    dist[node] = 0;

    while(!q.empty()){
        int curr_node = q.front();
        q.pop();
        for(auto child : adj[curr_node]){
            if(!vis[child]){
                q.push(child);
                dist[child] = dist[curr_node] + 1;
                vis[child] =1 ;
            }
            
        }
    }
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int t; cin >> t ;

while(t--){

int V , E , u, v;
cin>>V>>E;
for(int i =1 ; i<=V; i++) {
    adj[i].clear();
    }
vis.assign(V+1 , 0);
dist.assign(V+1 , 0);
while(E--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bfs(1);
cout << dist[V] << endl;
}
return 0;
}