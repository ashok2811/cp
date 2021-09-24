#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int W, int n){

        // Base Condition
        if(W==0 || n==0){
            return 0;
        }
        // Memoisation

        // Choice 1

        if(wt[n-1]<=W){

            //Take 
            int a  = val[n-1] + knapsack(wt, val, W-wt[n-1], n-1 );
            // Leave
            int b = knapsack(wt, val, W, n-1);

            return max(a, b);

        }
       
        //Choice 2
         else{
             return knapsack(wt, val, W, n-1);
         }
    
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n , W; 
    vector<int> wt;
    vector<int> val;

    cin >> n >> W;
    int temp;
    for(int i = 0 ; i< n ;i++){
        cin >> temp;
        wt.push_back(temp);
    }
    for(int i = 0 ; i< n ;i++){
        cin >> temp;
        val.push_back(temp);
    }

    cout << knapsack(wt, val, W, n);
  
    return 0;
}

