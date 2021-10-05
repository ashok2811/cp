#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
vector<int> vis;
vector<int> dist;
vector<int> primes;

bool isPrime(int n){
    for(int i = 2 ; i*i<=n ; i++){
        if(n%i==0) return 0;
    }
    return 1;
}

bool isValid(int a ,int b){
    int count = 0;
    while(a>0){
        if(a%10 != b%10) count++;
        a = a/10 ; b= b/10;
    }
    if(count==1) return true;
    
    return false;
}

void buildGraph(){
    for(int i = 1000; i<9999; i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }

    for( int i =0 ; i<primes.size(); i++){
        for(int j= i+1; j < primes.size(); j++){
            if(isValid(primes[i] , primes[j])){
                adj[primes[i]].push_back(primes[j]);
                adj[primes[j]].push_back(primes[i]);
            }
        }
    }
}

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

buildGraph();

int t; cin >> t ;

while(t--){

vis.assign(100001 , 0);
dist.assign(100001 , -1);
int a ,b;
cin >> a >>b;
bfs(a);

if(dist[b]==-1){
    cout << "Impossible"<<endl;
}
else{cout << dist[b] << endl;}

}
return 0;
}