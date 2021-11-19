#include <bits/stdc++.h>

using namespace std;

int n =100000 ;

vector<int> adj[100001];
vector<bool> visited;
vector<int> parent;
int c_start, c_end;

// DFS
bool dfs(int node, int par){
    visited[node] = true;
    for(int child : adj[node]){
        if(child == par) continue; // skip parent
        if(visited[child]){
            c_end = node;
            c_start = child;
            return true;
        }
        else{
            parent[child] = node;
            if(dfs(child, parent[child])) return true;
        }
    }
    return false;
}


//Detect and Print Cycle

void find_cycles(){
    visited.assign(n+1 , false);
    parent.assign(n+1 , -1);
    c_start = -1;

    for (int i = 1; i <=n; i++)
    {
        if(!visited[i] && dfs(i , parent[i])) break; // cycle found 
    }
    
    if(c_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    }

    else{
        vector<int> cycle;
        cycle.push_back(c_start);
        for(int i = c_end; i!=c_start; i = parent[i]){
            cycle.push_back(i);
        }
        cycle.push_back(c_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size()<<endl ;
        for (int node : cycle)
        {
            cout << node << " ";
        }
        cout << endl;
    }


}

int main(){

#ifndef ONLINE_JUDGE
 freopen("input.txt", "r" , stdin);
 freopen("output.txt", "w", stdout);
 #endif


     int V, E, u ,v;
     cin>>V >> E ;
     while(E--){
         cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u);
     }

     find_cycles();
 return 0;

}