class Solution {
public:
    
    int subsetSum(vector<int> &v, int n, int sum ){
       
    // Create a dp array
    int dp[n+1][sum+1];

    // Base Case -> Init
    for(int i= 1 ; i<=sum; i++) dp[0][i] = 0 ;  // making sum = s(i, i!=0) = 0 
    for(int i= 0 ; i<=n; i++) dp[i][0] = 1; // is it possible to make sum 0 -> always! 

    for(int i = 1; i<=n; i++){
        for(int j =0; j<=sum; j++){ // zero sum also allowed
            if(v[i-1]<=j){
                int a = dp[i-1][j-v[i-1]];
                int b = dp[i-1][j];

                dp[i][j] = a+b;
            }

            else{
                 dp[i][j] = dp[i-1][j];
            }

        }

    }
    

    return dp[n][sum];

}
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum =0 ;
        int n = nums.size();
           
        for(auto x : nums){
            sum+=x;
        }  
        
        if(abs(target)>sum || (sum + target)%2 !=0 ) return 0;

        return subsetSum(nums, n , (sum + target)/ 2);
        
    }
};