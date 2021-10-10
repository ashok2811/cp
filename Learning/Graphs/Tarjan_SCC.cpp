#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool vis[100001];
int in[100001];
int low[100001];
bool onStack[100001];
stack<int> st;
int timer =0;
int SCC = 0;
void dfs(int node){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    onStack[node] = true;
    st.push(node);
    for(auto child :adj[node]){
        if(!vis[child]){
            dfs(child);
            if(onStack[child]){
                low[node] = min(low[node] ,low[child]);
            }
            
        }

        else if(vis[child]){
            if(onStack[child]==true){
                low[node] = min(low[node] , in[child]);
            }
        }

    }

    if(in[node] == low[node]){
        SCC++;
        cout <<"SCC #" << SCC << endl;
        int u ;
        while(1){
            u = st.top();
            st.pop();
            onStack[u] = false;
            cout << u << " ";
            if(u == node) break;
        }
        cout <<endl<< "------------------" << endl;
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
}

for (int i = 1; i <=V; i++)
{
    vis[i] = onStack[i] = false;
}

for (int i = 1; i <=V; i++)
{
    if(!vis[i]){
        dfs(i);
    }
}


return 0;
}