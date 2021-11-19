# Tarjan's Algorithm for SCC

Practice Status: To-Do
Status: Done
Sub-Topic: SCC
Topic: Graphs

![20211010_111025.jpg](Tarjan's%20Algorithm%20for%20SCC%20916450f4c83f49dc8e53f11fdd177e9e/20211010_111025.jpg)

![20211010_111033.jpg](Tarjan's%20Algorithm%20for%20SCC%20916450f4c83f49dc8e53f11fdd177e9e/20211010_111033.jpg)

Code

```cpp
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
```

Input

```cpp
8 12
1 2
2 3
3 1
2 8
8 4
4 8
3 4
7 8
5 7
5 4
7 6
6 5
```

Output

```cpp
SCC #1
8 4 
------------------
SCC #2
3 2 1 
------------------
SCC #3
6 7 5 
------------------
```