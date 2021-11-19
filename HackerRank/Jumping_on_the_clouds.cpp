#include <bits/stdc++.h>

using namespace std;

 int dp[101];
int jump(vector<int>& v, int n){
    //base 
    if(v[n-1]==1) return INT_MAX-1;
    if(n==2 || n==3){
        return 1;
    }
    //Memo
    if(dp[n]!=-1) return dp[n];
    
    // choice
    int a = jump(v , n-1);
    int b = jump(v, n-2);
    
     dp[n] = 1 + min(a, b);
    
    
    return dp[n];
}

int jumpingOnClouds(vector<int> c) {
    
    return jump(c , c.size());
}

int main()
{   memset(dp, -1, sizeof(dp));
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}


