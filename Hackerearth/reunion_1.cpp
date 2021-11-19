#include <bits/stdc++.h>
using namespace std;

int par[100003];
int sz[100003];
char ar[100010];
void make_set(int v){
    par[i] =-1;
    sz[i] = 1;
}


int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int mx = 0 ;for(int i =1 ; i<=n ; i++){
    cin>>ar[i];
    if(ar[i]=='1'){
        make_set(i);
    }
}



return 0;
}