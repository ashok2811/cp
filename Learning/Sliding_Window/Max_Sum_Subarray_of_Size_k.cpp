#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&v, int n , int k){
    int sum = 0;
    int i = 0, j = 0;
    int mx = INT_MIN;
    while(j<n){
        sum = sum + v[j];
        if(j-i+1 <k){
            j++;
        }
        else if(j-i +1==k){
            mx = max(mx , sum);
            sum = sum - v[i];
            j++;
            i++;
        }
    }

    return mx;
}



int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

int n,k; cin >> n >> k;
vector<int> v(n,0);
for (int i = 0; i < n; i++){
    cin >> v[i];
}
cout << solve(v, n, k);
return 0;
}