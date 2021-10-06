#include <bits/stdc++.h>
using namespace std;
vector<int> adj[51];
vector<int> in;
vector<int> low;
vector<int> vis;

int timer;
void IS_AP(int node){
    cout << node << " is an articulation point" <<endl;
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


    for(int  i =1; i<=V; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int i =1 ; i<=V; i++){ // Clear the adj list for the future 
        adj[i].clear();
    }
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int n, m ;
cin>>n >>m;
for(int i = 1 ; i<=n; i++){
    for(int j =1 ; j<=m ;j++){
        char c ;
        cin >> c;
        if(c=='#'){
            adj[i].push_back(j);
        }
    }
}



ap(V);


return 0;
}