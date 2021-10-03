class Solution {
int dp[101][10001];   
public:
    Solution(){
         memset(dp , -1 , sizeof(dp));
    }
int solve(int egg, int floor){
        // Base conditions
        if(floor == 0 || floor == 1) return floor;
        if(egg == 1) return floor;
         if(egg == 0){return 0;}
        if(dp[egg][floor]!=-1) return dp[egg][floor];

        int mn = INT_MAX;
        int start = 1;
        int end = floor;
        while (start<=end)
        {
            int middle = (start + end)/2;
            int left = solve(egg-1, middle-1);
            int right = solve(egg , floor-middle);
            int temp = 1 + max(left, right);
            if(left<right){
                start = middle+1;
            }
            else{
                end = middle-1;
            }
            mn = min(mn , temp);
        }
        dp[egg][floor] = mn;
        return mn;
}

    
    int superEggDrop(int k, int n) {
       return solve(k , n);
    }
};