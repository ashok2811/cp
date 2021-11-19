#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(string &nums, int size){
    bool ans= false;
    for(int i = 0 ;i < size-1; i++){
        if(nums[i]==nums[i+1]){
            ans = true;
            break; 
        }
    }
    if(ans == true ){
        cout <<"YES"<<endl;
    }
    else{
        cout <<"NO"<<endl;
    }

}

int main(){

int t ; cin>>t;
while(t--){
    int n; 
    cin>>n;
    string s; cin >>s;

    solve(s, n);

}


return 0;
}