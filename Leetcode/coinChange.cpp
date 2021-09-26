class Solution {
public:
    
    long long mymin(long long a ,long long b){
        return (a>b)?b:a;
    }
    
    int coinChange(vector<int> &coins, int n , int val){
    
    //Init
    long long dp[n+1][val+1];
    for(int i = 0 ; i<=n; i++){dp[i][0]=0;}
    for(int i = 0 ; i<=val; i++){dp[0][i]=INT_MAX;}
    for(int i = 1 ; i<=val; i++){
        if(i%coins[0]==0){
            dp[1][i]=i/coins[0];}
        else dp[1][i]=INT_MAX;
        
    }
        
    
    //Choice 

    for (int i = 2; i <n+1; i++)
    {
        for (int j = 1; j < val+1; j++)
        {
                    
            if(coins[i-1]<=j){
                long long a =1+ dp[i][j - coins[i-1]];
                long long b = dp[i-1][j];
                dp[i][j] = mymin(a , b);
            }

            else{
                int c = dp[i-1][j];
                dp[i][j] = c;
            }

            //cout << dp[i][j] << " "; 
        }
        //cout << endl;
        
    }
    

    return (dp[n][val]!=INT_MAX) ? dp[n][val] : -1;
        

    
}
    
    int coinChange(vector<int>& coins, int amount) {
        return coinChange(coins, coins.size(), amount);
    }
};