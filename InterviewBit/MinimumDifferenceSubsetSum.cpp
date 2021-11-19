int subsetSum(vector<int> &v, int n, int sum ){
    if(n==1) return v[0];
    // Create a dp array
    int dp[n+1][sum+1];

    // Base Case -> Init
    for(int i= 1 ; i<=sum; i++) dp[0][i] = 0 ;  // making sum = s(i, i!=0) = 0 
    for(int i= 0 ; i<=n; i++) dp[i][0] = 1; // is it possible to make sum 0 -> always! 

    for(int i = 1; i<=n; i++){
        for(int j =1; j<=sum; j++){
            if(v[i-1]<=sum){
                int a = dp[i-1][j-v[i-1]];
                int b = dp[i-1][j];

                dp[i][j] = a||b;
            }

            else{
                 dp[i][j] = dp[i-1][j];
            }

        }
      
    }
    int mn =INT_MAX;
    for(int i =0; i<=sum/2; i++){
        if(dp[n][i]==1){
            mn = min(mn, sum - 2*i);
        }
    }

    return mn;

}

int Solution::solve(vector<int> &A) {

    int sum =0 ; 
    for(auto x : A){
        sum+=x;
    }

    return subsetSum(A, (int)A.size(), sum);


}
