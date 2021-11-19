#include <bits/stdc++.h>
using namespace std;
// Adjacency List Representation

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
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
    cout << u << " " << v << endl;
}



    return 0;
}
