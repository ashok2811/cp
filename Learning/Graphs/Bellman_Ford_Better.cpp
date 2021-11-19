 #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

struct edge{  //We maintain an edge list
    int a , b , cost;

};

int n , m , v;
vector<edge> e;
const int INF = 1000000000;

/*
This algorithm can be somewhat speeded up: 
often we already get the answer in a few phases 
and no useful work is done in remaining phases,
just a waste visiting all edges. So, let's keep 
the flag, to tell whether something changed in 
the current phase or not, and if any phase, nothing 
changed, the algorithm can be stopped.
*/

void solve(){
    vector<int> d(n+1, INF);
    d[v] = 0;
    for (;;)
    {
        bool any = false;

        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    any = true;
                }

        if (!any) break;
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