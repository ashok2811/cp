class Solution {
    int dp[201][20001];
    
public:
    
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    
    bool equalSum(vector<int> &nums, int sum, int n){
        if(sum == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        if(nums[n-1]<=sum){
            dp[n][sum] = equalSum(nums, sum-nums[n-1] , n-1) || equalSum(nums, sum, n-1);
            return dp[n][sum];
        }
        else{
            dp[n][sum] = equalSum(nums, sum, n-1);
            return dp[n][sum];
        }
        
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0 ;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2) return false;
        
        return equalSum(nums, sum/2, nums.size());   
        
        
    }
};