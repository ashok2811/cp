#include <bits/stdc++.h>
using namespace std;

string lcs(string x, string y, int n, int m){
    int dp[n+1][m+1];
    //Base Condition
    for(int i= 0; i<=n ;i++) dp[i][0] = i;
    for(int i= 0; i<=m ;i++) dp[0][i] = i; 

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(x[i- 1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j]);
            }
             
        }
    }

    string result = "";
    int i = n, j = m;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            result.push_back(x[i-1]);
            //cout << x[i-1] << "=";
            i--; j--;
        }
        else{
            if(dp[i][j-1]<dp[i-1][j]){
                result.push_back(y[j-1]);
               // cout << y[j-1] << "<";
                j--;
            }
            else{
                result.push_back(x[i-1]);
                //cout << x[i-1] << "^";
                i--;
            }
        }
    }
    while (i>0)
    {
        result.push_back(x[i-1]);
        i--;
    }
    while (j>0)
    {
        result.push_back(y[j-1]);
        j--;
    }
    
    
reverse(result.begin(), result.end());
    return result;    
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