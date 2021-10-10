#include <bits/stdc++.h>
using namespace std;


int main(){


int t; cin >> t ;
    while(t--){
    long long n; cin >> n ;
    long long sum = 0LL;
    long long arr[n];
    unordered_map<long long ,long long> mp; 
    for(int i =0; i<n; i++){
        cin >> arr[i] ;
        sum+=arr[i] ;
    }

    for(int i =0; i<n; i++){
        arr[i] *=n;
    }

    long long ans = 0;

    long long val1 = 2LL*sum ;
    for(int i = 0; i<n; i++){
        long long val2 = arr[i];
        if(mp.find(val1 -val2)!=mp.end()){
            ans += mp[val1-val2];
        }
        mp[val2]++;
    }
    cout << ans << endl;



}



return 0;
}