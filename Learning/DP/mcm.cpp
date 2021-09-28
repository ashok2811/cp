#include <bits/stdc++.h>
using namespace std;

long long dp[101][101];

int mcm(vector<int> &arr, int i, int j){

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


int main() {
    memset(dp, -1, sizeof(dp));

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n; 
    vector<int> arr;

    cin >> n;
    int temp;
    for(int i = 0 ; i< n ;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    

    cout << mcm(arr, 1, n-1);
  
    return 0;
}

