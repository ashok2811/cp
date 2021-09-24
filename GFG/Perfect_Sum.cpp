// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    int dp[101][10001];
    int MOD = 1000000007;
	public:
	
	Solution(){
	    
        memset(dp, -1, sizeof(dp));
    }
    
    int equalSum(int nums[], int sum, int n){
        if(sum == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        if(nums[n-1]<=sum){
            int a = equalSum(nums, sum-nums[n-1] , n-1);
            int b = equalSum(nums, sum , n-1);
            dp[n][sum] = (a%MOD + b%MOD)%MOD;
            return dp[n][sum];
        }
        else{
            int c = (equalSum(nums, sum , n-1))%MOD;
            dp[n][sum] = c;
            return dp[n][sum];
        }
        
    }
	
	int perfectSum(int arr[], int n, int sum)
	{
        
        return equalSum(arr, sum, n);   
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends