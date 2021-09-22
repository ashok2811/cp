// Method 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r =-1;
        int res =0, count =0; 
        int m[100] = {0};
        int n = s.length();
        while(r<n){
            if(count>0){
                m[s[l]-' ']--;
                if(m[s[l]-' ']==1)count--;
                l++;
                
            }
            else{
                r++;
                if(r==n) break;
                m[s[r]-' ']++;
                if(m[s[r]-' ']==2) count++;
                
            }
            if(count==0) res = max(res, r-l+1);
        }
        return res;
    }
};

//Method 2

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r =-1;
        int res =0, count =0; 
        unordered_map<char, int> m;
        int n = s.length();
        while(r<n){
            if(count>0){
                m[s[l]]--;
                if(m[s[l]]==1)count--;
                l++;
                
            }
            else{
                r++;
                if(r==n) break;
                m[s[r]]++;
                if(m[s[r]]==2) count++;
                
            }
            if(count==0) res = max(res, r-l+1);
        }
        return res;
    }
};