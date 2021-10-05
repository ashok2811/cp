#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
vector<int> vis;
vector<int> dist;

void bfs(int node){
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    dist[node] = 0;

    while(!q.empty()){
        int curr_node = q.front();
        q.pop();
        for(auto child : adj[curr_node]){
            if(!vis[child]){
                q.push(child);
                dist[child] = dist[curr_node] + 1;
                vis[child] =1 ;
            }
            
        }
    }
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int friends;
cin >> friends;
vis.assign(10001 , 0);
dist.assign(10001 , 0);

for(int i= 0 ; i < friends ;i++){
    int frnd, n_ffriend ; 
    cin >> frnd >> n_ffriend;
    adj[10000].push_back(frnd);
    adj[frnd].push_back(10000);
    for(int j = 0 ; j<n_ffriend ;j++){
        int ffriend ; cin >> ffriend;
        adj[frnd].push_back(ffriend);
        adj[ffriend].push_back(frnd);
    }
}



bfs(10000);
int count = 0;
for(int  i = 0; i<=9999 ;i++){
    if(dist[i]==2){
        count++;
        cout << i <<endl;
        }
}
cout << count << endl;
return 0;
}