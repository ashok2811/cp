class Solution {
public:
    int lcs(string x, string y , int n,  int m){
        int dp[n+1][m+1];
        for(int i = 0; i<=n ; i++){
            dp[i][0] = dp[0][i] = 0;
        }
        
        for(int i = 1 ; i <=n ; i++){
            for(int j =1 ; j <=m ; j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
                
               // cout << dp[i][j]<< " ";
            }
           // cout<< endl;
        }
        
        return dp[n][m];
    }
    
    
    
    int longestPalindromeSubseq(string s) {
        string x = s; 
        reverse(s.begin(), s.end());
        return lcs(x ,s , s.length(), s.length());
    }
};