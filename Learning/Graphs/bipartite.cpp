#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);

bool dfs(vector<int> adj[] ,  vector<int> &vis, vector<int> &col, int node, int color){
        vis[node] = 1;
        col[node] = color;

        for (auto child : adj[node])
        {
            if(!vis[child]){
                if(dfs(adj , vis , col,child, color^1)==false){
                    return false;
                }
            }

            else{
                if(col[node] == col[child]){
                    return false;
                }
            }
        }
        
    return true;

}


int main(){
 fastIO   
#ifndef ONLINE_JUDGE
freopen("input.txt", "r" , stdin);
freopen("output.txt", "w", stdout);
#endif

int T;
cin >> T;
for (int k =1 ; k <=T ; k++)
{


    int V, E, u , v;
    cin >> V >> E;

    vector<int> adj[V+1];
    vector<int> vis(V+1,0);
    vector<int> color(V+1);
    while (E--)
    {
        cin >> u>> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

        int ans = 1;

            for (int i = 1; i <= V; ++i)
            {

                if (!vis[i]) {
                    if (dfs(adj, vis, color , i , 1) == false) {
                        ans  = 0;
                        break;
                    }

                }
            }




    cout << "Scenario #" << k << ":" << endl;
    (ans) ? cout << "No suspicious bugs found!\n" : cout << "Suspicious bugs found!\n" ;

}

return 0;
}