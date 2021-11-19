 #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

struct edge{
    int a , b , cost;

};

int n , m , v;
vector<edge> e;
const int INF = 1000000000;

void solve(){
    vector<int> d(n+1, INF);
    d[v] = 0;
    for(int i = 0; i< n-1; ++i){
        for(int j = 0; j< m; ++j){
            if(d[e[j].a] < INF){
                d[e[j].b] = min(d[e[j].b] , d[e[j].a] + e[j].cost);
            }
        }
    }
    for(int i = 0 ; i< n ; i++){
        cout << d[i] << " ";
    }
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif


cin >> n >> m >> v;
int k = m;
while(k--){
    edge temp;
    cin >> temp.a >> temp.b >> temp.cost;
    e.push_back(temp); 
}

solve();


return 0;
}