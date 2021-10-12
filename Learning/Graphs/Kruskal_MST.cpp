#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a ;
    int b ;
    int w;
};

edge ar[100000];
vector<int> par(10001, -1);
vector<int> Rank(10001, 1);

bool comp(edge a , edge b){
    if(a.w < b.w) return true;
    return false;
}

int Find_set(int v){
    if(par[v] == -1) return v;
    return par[v] = Find_set(par[v]);

}

void Union_set(int a, int b){
        a = Find_set(a);
        b = Find_set(b);
        if(a!=b){
            if(Rank[a] <Rank[b])
                swap(a, b); //
            par[b] = a;
            Rank[a] += Rank[b];
        }
        
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int n, m , a, b , w;
cin >> n >> m;


for (int i = 0; i < m; i++)
{
    cin >> ar[i].a >> ar[i].b >> ar[i].w;
}

int sum =0;
sort(ar, ar + m, comp);


for(int i =0 ; i< m ; i++){
    a=Find_set(ar[i].a);
    b=Find_set(ar[i].b);
    if(a!=b){
        sum += ar[i].w;
        Union_set(a ,b);
    }
}

cout << sum<< endl;

return 0;
}