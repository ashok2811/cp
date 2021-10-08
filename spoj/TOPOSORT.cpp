#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000001];
vector<int> indegree;
vector<int> toposort;

void PRINT_TSORT(int V){
    for(int i= 0 ; i<V ; i++) cout << toposort[i] << " ";
    cout << endl;
}

void bfs(int V){
    priority_queue<int,vector<int>,greater<int> > q;
   
    for(int i = 1 ; i<=V ;i ++){ // Checking initial indegree
        if(indegree[i]==0){
            q.push(i);
        }
    }    
        while(!q.empty()){
        int curr_node = q.top();
        q.pop();
        toposort.push_back(curr_node);
        for(auto child : adj[curr_node]){
            indegree[child]--;
            if(indegree[child] ==0){
                q.push(child);
            }            
        }
    }
    if(toposort.size()==V){
        PRINT_TSORT(V);
    }
    else{
        cout << "Sandro fails." << endl; 
    }
    
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int V , E , u, v;
cin>>V>>E;
indegree.assign(V+1,0);
while(E--){
    cin >> u >> v;
    adj[u].push_back(v);
    indegree[v]++;
    }

bfs(V);
return 0;
}