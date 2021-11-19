// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string x, string y, int n, int m)
    {
        int dp[n+1][m+1];
    //Base Condition
    for(int i= 0; i<=n ;i++) dp[i][0] =0;
    for(int i= 0; i<=m ;i++) dp[0][i] =0; 

    int maxL = 0;
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j] = 0;
            }

            maxL = max(maxL, dp[i][j]);
            //cout << dp[i][j] <<" ";
        }
        //cout << endl;
    }
    
return maxL;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends