#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], vector<int>& vis, int node){
        vis[node] =1 ;
        cout << " <-> " << node ; 
        for (auto child : adj[node])
        {
            if(!vis[child]) dfs(adj ,vis, child);   
        }
        
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int v , e ; 
cin >> v >> e;
vector<int> adj[v];
vector<int> visited(v, 0);

while (e--)
{
    int u, v;
    cin >> u >> v;
    addEdge(adj, u , v);
}
    int cc= 0;
    for(int i = 0 ; i< v; i++){
        if(!visited[i]){
            cout << "Connected Components are " ;
            dfs(adj, visited , i);
            cout << endl;
            cc++;
        }
        
    }

    cout << "Total Connected Components: " <<cc << endl;

    return 0;
}
