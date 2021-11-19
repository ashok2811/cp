/*      
        great                 
        /   \
      gr     eat 
      /\     / \
     g  r   e  at 
               / \
              a   t
              
         rgeat 
        /   \
      rg     eat 
      /\     / \
     r  g   e  at 
               / \
              a   t
*/

class Solution {
public:
    
    unordered_map<string, bool> mp; // Creating a map for lookup
    
    bool solve(string a , string b){
        // base condition 
        if(a.compare(b)==0) return true; // if a==b
        if(a.length()<=1) return false; //   we have checked a!=b but if a.length()==1 they can't be scrambled     
        
        // lookup in the map
        string key = a;
        key.push_back('_');
        key.append(b);
        
        // Now key is a_b        
        if(mp.find(key)!=mp.end()){ // key already exists
            return mp[key];
        }
        int n = a.length();
        bool flag = false;
        // propagate recursion using give 2 conditions
        
        for( int i = 1 ; i <= n-1; i++){
            
            if((
                solve(a.substr(0, i) , b.substr(n-i, i)) &&
                solve(a.substr(i, n-i) , b.substr(0, n-i))
            ) || 
              (
                solve(a.substr(0, i) , b.substr(0, i)) &&
                solve(a.substr(i, n-i) , b.substr(i, n-i))
              
              )){
                flag  =true;
                break;
            }
            
        }       
   // save the output in the map
        mp[key] = flag;
    return flag;     
     
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};