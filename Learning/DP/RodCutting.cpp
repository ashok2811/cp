#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> &prices, int len){
    
    //Init
    int lenArr[len];
    for (int i = 0; i < len; i++)
    {
        lenArr[i] = i+1;
    }
    
    int dp[len+1][len+1];
    for(int i = 0 ; i< len; i++){dp[0][i]=0, dp[i][0]=0;}
    
    //Choice 

    for (int i = 1; i <len+1; i++)
    {
        for (int j = 1; j < len+1; j++)
        {
                    
            if(lenArr[i-1]<=j){
                int a = prices[i-1] + dp[i][j - lenArr[i-1]];
                int b = dp[i-1][j];
                dp[i][j] = max(a, b);
            }

            else{
                int c = dp[i-1][j];
                dp[i][j] = c;
            }

            cout << dp[i][j] << " "; 
        }
        cout << endl;
        
    }
    

    return dp[len][len];
        

    
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T; cin >> T;
    while (T--)
    {
        int len; cin >>len;;
        vector<int> v;
        int t;
        for (int i = 0; i < len; i++)
        {
            cin>>t; 
            v.push_back(t);
        }

        cout << rodCutting(v,len) << endl;
        
    }
    

}