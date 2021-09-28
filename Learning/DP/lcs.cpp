#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int lcs(string x, string y, int n, int m){
    if(n ==0 || m == 0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(x[n-1] == y[m-1]) {
        dp[n][m] = 1  + lcs(x, y , n-1, m-1);
        return dp[n][m];}
    else{
        dp[n][m] = max(lcs(x,y,n-1,m), lcs(x,y,n,m-1)); 
        return dp[n][m];}
}
int main(){
memset(dp, -1, sizeof(dp));
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T; cin >> T;
    while (T--)
    { 
        string x, y;
        cin>>x >>y;

        cout << lcs(x, y , x.length(), y.length()) << endl;
        
    }
    

}