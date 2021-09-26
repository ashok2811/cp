#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int n , int val){
    
    //Init
    int dp[n+1][val+1];
    for(int i = 0 ; i<=n; i++){dp[i][0]=1;}
    for(int i = 0 ; i<=val; i++){dp[0][i]=0;}
    
    //Choice 

    for (int i = 1; i <n+1; i++)
    {
        for (int j = 1; j < val+1; j++)
        {
                    
            if(coins[i-1]<=j){
                int a = dp[i][j - coins[i-1]];
                int b = dp[i-1][j];
                dp[i][j] = a + b;
            }

            else{
                int c = dp[i-1][j];
                dp[i][j] = c;
            }

            cout << dp[i][j] << " "; 
        }
        cout << endl;
        
    }
    

    return dp[n][val];
        

    
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T; cin >> T;
    while (T--)
    {
        int n, val; cin >> n>>val;;
        vector<int> coins;
        int t;
        for (int i = 0; i < n; i++)
        {
            cin>>t; 
            coins.push_back(t);
        }

        cout << coinChange(coins, n , val) << endl;
        
    }
    

}