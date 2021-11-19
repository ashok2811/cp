// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

int mp[201][201][2];

Solution(){
    memset(mp ,-1, sizeof(mp));
}

int solve(string s, int i , int j, bool isTrue){
        //Base 
        if(i>j) return 1;
        if (i==j)
        {
            if(isTrue==true){ // If we are checking for true
                return s[i]=='T'; 
            }
            else{ // If we are checking for false
                return s[i] =='F';
            }
        }

        //Memoization
        
        // string temp = to_string(i);
        // temp.push_back(' ');
        // temp.append(to_string(j));
        // temp.push_back(' ');
        // temp.append(to_string(isTrue));

        //if(mp.find(temp)!=mp.end()) return mp[temp];
        if(mp[i][j][isTrue]!= -1) return mp[i][j][isTrue]; 
        // Temp ans
        long long ans = 0;
        for (int k = i+1; k <= j-1; k=k+2)  // k will always be at operators
        {
            int lt = solve(s, i , k-1, true);
            int lf = solve(s, i , k-1, false);
            int rt = solve(s, k+1, j, true);
            int rf = solve(s, k+1, j, false);

            // For each operator
            if(s[k]=='&'){

                if(isTrue==true){
                    ans = ans + lt*rt;
                }

                else{
                    ans = ans + lt*rf + lf*rf + lf*rt;
                }

            }

            else if(s[k]=='|'){
                if(isTrue==true){
                    ans = ans + lt*rf + lt*rt + lf*rt;
                }

                else{
                    ans = ans + lf*rf;
                }
            }

            else if(s[k]=='^'){
                if(isTrue==true){
                    ans = ans + lt*rf + lf*rt;
                }

                else{
                    ans = ans + lt*rt + lf*rf;
                }
            }

        }
        ans = ans%1003;
        mp[i][j][isTrue] = ans;
        //  cout <<i << " "<< j << " "  << isTrue <<" " << mp[i][j][isTrue] << endl;
        
        // Return Variable

        return ans;
}

    int countWays(int N, string S){
        // code here
        return solve(S, 0, N-1 , true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends