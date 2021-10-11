#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int size[100002];
int parent[100002];
char X[100003];
void make_set_size(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int a){
    if(parent[a] == a) return a;
    parent[a] = find_set(parent[a]);
    return parent[a];
}

void union_set_size(int a, int b){ // use this 
    
    a =find_set(a);
    b =find_set(b);
    if(a!=b){
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input1.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif  
int sz = 0;

int n ,k ;
cin >> n >> k;

for(int i =1 ; i<=n; i++){
    cin>>X[i];
    if(X[i]=='1'){ 
    make_set_size(i);
    if(i>1 && X[i-1]=='1') union_set_size(i, i-1);

    int p = find_set(i);
    if(size[p] > sz){
        sz = size[p];
    }
}

while(k--){
    int qt;
    
    cin >> qt;
    if(qt==1){
        cout <<sz <<endl;
    }
    else if(qt==2){
        int v ; cin>>v;
        if(X[v] == '1' ) continue;
        make_set_size(v);
        X[v] = '1';
        if(v>1 && X[v-1]=='1') union_set_size(v, v-1);
        if(v<n && X[v+1]=='1') union_set_size(v, v+1);
        int p = find_set(v);
        if(size[p] > sz){
            sz = size[p];
        }
    }
}

for (int i = 1 ; i <=n; i++){
    cout << size[i] << " ";
}


return 0;
}