#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200001];

int vis[300001], low[300001], in[300001];
int timer = 0;
bool flag  =false;
set<pair<int, int>> roads;
void dfs(int node, int parent){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    if(parent!=-1){
        roads.insert({parent, node});
    }
    for(auto child :adj[node]){
        if(child == parent) continue;
        else if(vis[child]){
            // Back-Edge
            if(in[child] < in[node]){
            roads.insert({node, child});
            //cout<< node<<" "<< child << " Back-Edge" << endl;
            }
            low[node] = min(low[node], in[child]);
        }
        else{
            dfs(child,node);
            if(low[child] > in[node]){
              flag  =1;
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

if(flag ==1){
    cout<<0<< endl;
}
else{
for(auto x : roads){
    cout << x.first << " " << x.second<<endl;
}

}

return 0;
}