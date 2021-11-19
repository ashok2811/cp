#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
vector<int> adj_tr[1001];

vector<int> order;
vector<int> SCC;

int vis[1001];

void dfs(int node){
    vis[node] =1;
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs1(int node){
     vis[node] =1;
    for(int child : adj_tr[node]){
        if(!vis[child]){
            dfs1(child);
        }
    }
    SCC.push_back(node);
}


int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int t ; cin >>t ;
while(t--){

int V , E , u, v;
cin>>V>>E;

for(int i=1;i<=V; i++){
    adj[i].clear();
    adj_tr[i].clear();
    vis[i] = 0;
}
order.clear();



while(E--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj_tr[v].push_back(u);
}

for (int i = 1 ; i<=V; i++){
    if(!vis[i]) dfs(i);
}
for (int i = 1 ; i<=V; i++){
    vis[i] = 0;
}

for (int i = 1 ; i<=V ; i++){
    
    if(vis[order[V-i]] == 0){
        SCC.clear();
        dfs1(order[V-i]);

        cout << "dfs1() called from " << order[V-i] << " and printing SCC" <<endl;
        for(int node: SCC){
            cout << node << " ";
        }
        cout <<endl;
    }
}


}



return 0;
}