class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int best = INT_MIN;
        int maxProd =1;
        int minProd = 1;
        
        for(int i = 0 ; i< nums.size(); i++){
            int n = nums[i];
            // Swap if current number is negative
            if(n < 0){
                swap(maxProd, minProd);
            }
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            
            // Update the best
            best = max(best , maxProd);
        }
        
        return best;
    }
};