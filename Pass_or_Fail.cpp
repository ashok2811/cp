#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){

int t ; cin>>t;
while(t--){
    int N,X, P;
    cin >>N>>X>>P;
    bool ans;

    if(3*X - (N-X) >=P){
        ans = true;
    }
    else{
        ans = false;
    }

    if(ans){
        cout <<"PASS" <<endl;
    }
    else{
        cout<<"FAIL"<<endl;
    }
    
}


return 0;
}