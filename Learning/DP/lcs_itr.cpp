#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m){
    int dp[n+1][m+1];
    //Base Condition
    for(int i= 0; i<=n ;i++) dp[i][0] =0;
    for(int i= 0; i<=m ;i++) dp[0][i] =0; 

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
    
return dp[n][m];
    
}
int main(){
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