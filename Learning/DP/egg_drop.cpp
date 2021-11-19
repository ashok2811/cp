#include <bits/stdc++.h>

using namespace std;
int dp[101][10001];
int solve(int egg, int floor){
        // Base conditions
        if(floor == 0 || floor == 1) return floor;
        if(egg == 1) return floor;
         if(egg == 0){return 0;}
        if(dp[egg][floor]!=-1) return dp[egg][floor];

        int mn = INT_MAX;
        // Recursive Cond
        for(int k =1 ; k<=floor ; k++){
            // Break 
            //cout << k << " " << mn << endl;
            int low , high;

            if(dp[egg-1][k-1]!=-1){
                low = dp[egg-1][k-1];
            }
            else{
                low = solve(egg-1, k-1);
                dp[egg-1][k-1] = low;
            }

             if(dp[egg][floor-k]!=-1){
                high = (dp[egg][floor-k]);
            }
            else{
                high = solve(egg, floor- k);
                dp[egg][floor-k] = high;
            }


            int temp = 1 + max( low , high);
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