// It a tree 

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int vis[10001];

void dfs(int node){
    vis[node] = 1;
    for(auto child : adj[node]){
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

int V, E, u , v;

cin >> V >>E ;
int edges = E;
while(E--){
    cin >> u >> v ;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int cc = 0 ;
for(int i =1 ; i<=V; i++){
    if(!vis[i]){
        dfs(i);
        cc++;
    }
}

if(V == edges+1 && cc==1){
    cout<<"YES"<<endl;
}

else cout << "NO" <<endl;

return 0;

}