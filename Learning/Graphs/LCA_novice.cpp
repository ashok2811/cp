#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[100001];
int level[100001];
int parent[100001];

void bfs(int node){
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    level[node] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto child : adj[curr]){
            if(!vis[child]){            
            q.push(child);
            vis[child] = 1;
            level[child] = level[curr] + 1 ;            
            parent[child] = curr;
            }
            
        }
    }
    
}

int LCA(int node1, int node2){
    if(level[node1]>level[node2]) 
        swap(node1,node2);
    
    int d = level[node2] - level[node1];
    while(d > 0){
        node2 = parent[node2];
        d--;
    }
    if(node1 == node2){ return node1; }

    while(parent[node1] != parent[node2]){
        node1 = parent[node1];
        node2 = parent[node2];
    }
    return parent[node1];
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

bfs(1);

cout << LCA(9 , 8) << endl;


return 0;
}