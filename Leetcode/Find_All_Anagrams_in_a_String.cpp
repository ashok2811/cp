class Solution {
public:
    vector<int> findAnagrams(string s1, string s2) {
        vector<int> ans;
        int n = s1.length();
        int k = s2.length();
        unordered_map<char, int> m;

        for(int i = 0 ; i< k ; i++){
            m[s2[i]]++;
        }
        int cnt = m.size();
        int i = 0, j = 0;
        while(j<n){

            if(m.find(s1[j])!=m.end()){
                m[s1[j]]--;
                if(m[s1[j]]==0){
                    cnt--;
                }
            }

            if(j-i+1 <k){
                j++;
            }
            else if(j-i +1==k){

                if(cnt==0){
               
                ans.push_back(i);
                  }

                if(m.find(s1[i])!=m.end()){
                    m[s1[i]]++;
                    if(m[s1[i]]==1) cnt++;
                }

                //slide the window
                j++;
                i++;
            }
        }
        
        return ans;
        
    }
};