#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
typedef long long ll;
typedef vector<int> vi;
/*-----------------------------------------*/

vector<pair<int,int>> adj[1001];
vector<int> dist(1001, 0);

void djisktra(int V, int node){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> dist(V+1, INF);
    pq.push({0 ,node});
    dist[node] = 0;

    while(!pq.empty()) {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        for(auto x :adj[curr]) {
            if(curr_d + x.second < dist[x.first]) {
                dist[x.first] = curr_d + x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }

    for(int i =1 ; i<=V; i++){
        cout <<"i: " << i << " " <<dist[i] << endl;
    }
    
    }

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int t ; cin >> t ;
while(t--){

int V,E, a ,b , w;
cin >> V>>E;
dist.assign(V+1 ,0);

while(E--){

    cin>>a>>b>>w;

    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
}

    djisktra(V, 1);
}



return 0;
}