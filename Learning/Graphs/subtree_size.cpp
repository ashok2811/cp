#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
vector<int> vis;
vector<int> sub_size;

int dfs(int node){
    vis[node] =1;
    int curr =1 ;
    for(auto child : adj[node]){
        if(!vis[child]){
            curr += dfs(child);
        }
    }
    sub_size[node] = curr;
    return curr;
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int V , E , u, v;
cin>>V;
E = V-1;
while(E--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vis.assign(V+1 , 0);
sub_size.assign(V+1 , 0);

cout << dfs(1) << endl;

for(int i =1 ; i<=V; i++){
    cout << sub_size[i] << " " ;
}
cout << endl;

return 0;
}