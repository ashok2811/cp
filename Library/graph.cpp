#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[100001];

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


return 0;
}