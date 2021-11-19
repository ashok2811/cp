#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[100001];
int level[100001];
int lca[100001][20];
int N;
int maxN;
void bfs(int node) {
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    level[node] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto child : adj[curr]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = 1;
                level[child] = level[curr] + 1 ;
                lca[child][0] = curr;
            }

        }
    }

}

void init() {
    bfs(1);

    // for(int j =1 ;j<=maxN ;j++){
    //     for(int i =1 ;i<=N ;i++){
    //         if(lca[i][j-1] != -1){
    //             int par = lca[i][j-1];
    //             lca[i][j] = lca[par][j-1];
    //         }
    //     }
    // }
}

int LCA(int node1, int node2) {
    if (level[node1] > level[node2])
        swap(node1, node2);

    int d = level[node2] - level[node1];
    while (d > 0) {
        int i = log2(d);
        node2 = lca[node2][i];
    }
    if (node1 == node2) { return node1; }

    for (int i = maxN; i >= 0; i--) {
        if (lca[node2][i] != -1 && (lca[node2][i] != lca[node1][i])) {
            node1 = lca[node1][i];
            node2 = lca[node2][i];
        }
    }
    return lca[node2][0];
}


int main() {
    memset(lca, -1, sizeof(lca));
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int V , E , u, v;
    cin >> V >> E;
    N = V;
    maxN = log2(N);
    while (E--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init();

    cout << LCA(9 , 8) << endl;


    return 0;
}