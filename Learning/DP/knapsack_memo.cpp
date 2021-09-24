#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int knapsack(vector<int> &wt, vector<int> &val, int W, int n){

        // Base Condition
        if(W==0 || n==0){
            return 0;
        }
        // Memoisation
        if(dp[n][W]!=-1) return dp[n][W];

        // Choice 1

        if(wt[n-1]<=W){

            //Take 
            int a  = val[n-1] + knapsack(wt, val, W-wt[n-1], n-1 );
            // Leave
            int b = knapsack(wt, val, W, n-1);
            dp[n][W] = max(a, b);
            return max(a, b);

        }
       
        //Choice 2
         else{
             int c = knapsack(wt, val, W, n-1);
             return c;
         }
    
}


int main() {
    memset(dp, -1, sizeof(dp));

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

