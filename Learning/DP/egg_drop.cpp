#include <bits/stdc++.h>

using namespace std;
int dp[101][10001];
int solve(int egg, int floor){
        // Base conditions
        if(floor == 0 || floor == 1) return floor;
        if(egg == 1) return floor;

        if(dp[egg][floor]!=-1) return dp[egg][floor];

        int mn = INT_MAX;
        // Recursive Cond
        for(int k =1 ; k<=floor ; k++){
            // Break 
            int temp = 1 + solve(egg-1, k-1) + solve(egg, floor-k);
            //Did not break 
            mn = min(mn, temp);
        } 

        dp[egg][floor] = mn;
        return mn;


}


int main(){
memset(dp , -1 , sizeof(dp));
#ifndef ONLINE_JUDGE
    freopen("input.txt" ,"r" ,stdin);
    freopen("output.txt" ,"w" ,stdout);    
#endif

int egg, floors;
cin >> egg >> floors;

 cout << solve(egg, floors) << endl;


}