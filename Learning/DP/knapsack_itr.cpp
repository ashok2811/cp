#include <bits/stdc++.h>
using namespace std;



int knapsack(vector<int> &wt, vector<int> &val, int W, int n){
vector<vector<int>> dp(n + 1, vector<int>(W + 1));

for(int i = 1; i<=n; i++){
    for (int j = 1; j <=W; j++)
    {
        //Choice 1
            if(wt[i-1]<=j){
            // Choice 1.1
            int a = val[i-1] + dp[i-1][j-wt[i-1]]; 

            // Choice 1.2    

            int b = dp[i-1][j];

            dp[i][j] = max(a , b);
            }
            
        
        // Choice 2
            else{
                dp[i][j] = dp[i-1][j];
            }
            cout << dp[i][j] << " ";
    }
    cout << endl;
}

return dp[n][W];

}


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n , W; 
    vector<int> wt;
    vector<int> val;

    cin >> n >> W;
    int temp;
    for(int i = 0 ; i< n ;i++){
        cin >> temp;
        wt.push_back(temp);
    }
    for(int i = 0 ; i< n ;i++){
        cin >> temp;
        val.push_back(temp);
    }

    cout << knapsack(wt, val, W, n);
  
    return 0;
}

