#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int size[10001];
int parent[10001];
int Rank[10001];

void make_set_size(int v){
    parent[v] = v;
    size[v] = 1;
}

void make_set_rank(int v){
    parent[v] = v;
    Rank[v] = 0;
}

int find_set(int a){
    if(a = parent[a]) return a;
    return parent[a] = find_set(parent[a]);
}

void union_set_size(int a, int b){ // use this 
    a =find_set(a);
    b = find_set(b);
    if(a!=b){
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

void union_set_rank(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(Rank[a]<Rank[b]){
            swap(a ,b);
        }
        parent[b] = a;
        if(Rank[a]==Rank[b]){
            Rank[a]++;
        }
    }
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif


return 0;
}