class Solution {
public:
    
    int jump(vector<int>& nums) {
        int jump = 0, range = 0, mrange =0;
        int n = nums.size();
        for(int i = 0 ; i< n-1 ; i++){
            mrange = max(mrange , i + nums[i]);
            if(i == range){
                jump++;
                range = mrange;
            }
        }
        return jump;    
        }
};