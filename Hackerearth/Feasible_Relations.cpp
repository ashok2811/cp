#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000001];
int vis[1000001];
int curr_cc =0;
int cc[1000001];


void dfs(int node){
    vis[node]  =1 ;
    cc[node] = curr_cc;
    for(int child : adj[node]){
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

int t ; cin >>t ;
while(t--){
int V , E , u, v;
cin>>V>>E;

vector<pair<int ,int>> edgeList;

for(int i =1 ; i<= V ; i++){
    adj[i].clear();
    vis[i] = 0;
}
string s;

while(E--){
    cin >> u >>s>> v;
    if(s=="="){
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    else{
        edgeList.push_back({u , v});
    }
    
}

for(int i = 1 ; i <=V; i++){
    if(!vis[i]){
        curr_cc++;
        dfs(i);
    }
}


bool flag = true;

for(int i = 0 ; i<edgeList.size(); i++){
    u = edgeList[i].first;
    v = edgeList[i].second;
    if(cc[u]==cc[v]){
        flag = false;
        break;
    }
}

if(flag){
    cout << "YES" << endl;
}
else cout << "NO" << endl;

}


return 0;
}