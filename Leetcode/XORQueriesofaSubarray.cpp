class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> prefix;
        prefix.push_back(arr[0]);
        for(int i = 1 ;i< arr.size(); i++){
            prefix.push_back(arr[i]^prefix[i-1]);
        }
        
        for(auto x :queries){
            if(x[0]==x[1]){
               ans.push_back(arr[x[0]]);
            }
            else if(x[0]==0){
                ans.push_back(prefix[x[1]]); 
            }
            else{
                ans.push_back(prefix[x[0]-1]^prefix[x[1]]);
            }
        }
        return ans;
    }
};