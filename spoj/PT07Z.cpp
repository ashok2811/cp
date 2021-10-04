#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
vector<int> vis;

int maxD, maxNode;
void dfs(int node, int d){
        vis[node] =1;
        if(d > maxD){
            maxD = d;
            maxNode = node;
        }

        for(auto child : adj[node]){
            if(!vis[child]){
                dfs(child , d+1);
            }
        }
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
maxD = -1;
dfs(1 ,0);
//cout << maxD  << " "<< maxNode << endl;
maxD =-1;
vis.assign(V+1 , 0);
dfs(maxNode, 0);
cout << maxD <<endl;
return 0;
}