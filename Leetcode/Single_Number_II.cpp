class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> f(32, 0);
        
        for(auto x : nums){
          for(int i = 0 ; i<32; i++){
            
                if(x&(1<<i)) f[i]++;
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i<32; i++){
            if(f[i]%3==1) {
                ans += (1<<i);
            } 
        }
        
        return ans;
    }
};