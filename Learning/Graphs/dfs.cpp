#include <bits/stdc++.h>
using namespace std;
// Adjacency List Representation

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], vector<int> &visited, int node){
        visited[node]=1;
        cout << node << " ";
        for (auto child: adj[node]) // for all childs belonging to adj list of current node
        {
            if(!visited[child]){ // if not visited
                dfs(adj ,visited, child); // visit that child
            }
        }
        
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int V , E ; 
cin >> V >> E;
vector<int> adj[V];
vector<int> visited(V, 0);

while (E--)
{
    int u, v;
    cin >> u >> v;
    addEdge(adj, u , v);
}

for (int i = 0; i < V; ++i)
	{
        
		if (!visited[i]) {
			dfs(adj, visited , i);
			
		}
	}
    return 0;
}
