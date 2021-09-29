class Solution {
    int dp[2001][2001];
    public:
    Solution(){
        memset(dp , -1, sizeof(dp));
    }
    
 bool isPalindrome(string &s,int i,int j)
    {
       while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
    }
    
    int solve(string s, int i ,int j){
        if(i>=j || isPalindrome(s, i, j)){
            dp[i][j]=0;
            return 0;
        } 
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mn = INT_MAX;
        for(int k = i; k < j; k++){
            int temp = 1 + solve(s, i , k) + solve(s, k+1, j);
            mn = min(mn , temp);
            if(temp <= mn){
                mn = temp;
            }
        }
        dp[i][j] = mn;
        return mn;
    }
    
    int minCut(string s) {
        return solve(s, 0, s.length()-1);    
    }
};