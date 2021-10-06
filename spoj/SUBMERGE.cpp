#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
vector<int> in;
vector<int> low;
vector<int> vis;
set<int> s;
int timer;
void IS_AP(int node){
    s.insert(node);
}

void dfs(int node, int parent =-1){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    int children =0 ;
    for(auto child :adj[node]){
        if(child==parent) continue;

        if(vis[child]){
            // Backedge;
            low[node] = min(low[node], in[child]);
        }
        else{
            dfs(child , node);
            low[node] = min(low[child], low[node]);
            if(low[child]>= in[node] && parent!= -1){ // Condition for articulation point
                IS_AP(node);
            }
             children++;
        }   
       
    }
     if(parent == -1 && children>1 ){ // Checking the root for AP
                IS_AP(node);
        }

}

void ap(int V){
    timer = 0;
    in.assign(V+1, -1);
    low.assign(V+1, -1);
    vis.assign(V+1, 0);


    dfs(1);
    cout << s.size() << endl;
    for(int i = 1 ; i <=V ; i++) adj[i].clear();
    s.clear();

}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int V =-1 , E = -1 , u, v;

while(1){
    cin>>V>>E;
    if(V==0 && E==0) return 0;
    while(E--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    
    ap(V);
}



 
return 0;
}