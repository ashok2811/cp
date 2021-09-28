// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

long long dp[101][101];
class Solution{
public:

    Solution(){
        
    memset(dp, -1, sizeof(dp));
    }


int mcm(int arr[], int i, int j){

        // Base Condition
        if(i>=j){
            return 0;
        }
        // Memoisation
        if(dp[i][j]!=-1) return dp[i][j];

        int mn = INT_MAX;

        for(int k = i ; k<=j-1; k++){
            long long temp ;
            temp = mcm(arr, i ,k) + mcm(arr, k+1, j)+
                    arr[i-1]*arr[k]*arr[j];
            mn = min(mn , (int)temp);
        }
        dp[i][j] = mn;
       return mn;
}

    int matrixMultiplication(int N, int arr[])
    {
        return mcm(arr, 1 ,N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends