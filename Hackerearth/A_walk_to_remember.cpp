#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef vector<int> vi;
#define Rep(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for(auto& a : x)
#define nl '\n'
#define ri(n) int n; scanf("%d", &n);
#define rll(n) ll n; scanf("%lld", &n);
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
void TXT_IO(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> adj[200001];
vector<int> adj_tr[200001];

vector<int> order;
vector<int> SCC;

int vis[200001];
int ans[200001];

void dfs(int node){
    vis[node] =1;
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs1(int node){
     vis[node] =1;
    for(int child : adj_tr[node]){
        if(!vis[child]){
            dfs1(child);
        }
    }
    SCC.push_back(node);
}



int main() {
fastIO
TXT_IO();
int T=1;
while (T--) {

int V , E , u, v;
cin>>V>>E;

while(E--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj_tr[v].push_back(u);
}

for (int i = 1 ; i<=V; i++){
    if(!vis[i]) dfs(i);
}
for (int i = 1 ; i<=V; i++){
    vis[i] = 0;
}

 for (int i = 1 ; i<=V ; i++){
    
    if(vis[order[V-i]] == 0){
        SCC.clear();
        dfs1(order[V-i]);

        if(SCC.size()>=2){
            for(auto x : SCC){
                ans[x] = 1;
            }
        }
    }
}

for (int i = 1 ; i <=V; i++){
    cout << ans[i] << " ";
}

	}
	return 0;
}