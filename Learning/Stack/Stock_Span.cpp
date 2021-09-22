#include <bits/stdc++.h>
using namespace std;

vector<int> stock(vector<int>&v){
    vector<int> ans;
    stack<pair<int, int>> s;

    int len=v.size();
    for(int i=0 ; i<len; i++){

        if(s.size()==0){         
            ans.push_back(-1);
        }
        else if(s.size()>0 && s.top().first>v[i]){
            ans.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first<=v[i]){
            while (s.size()>0 && s.top().first<=v[i])
            {
                s.pop();
            }
            if(s.size()==0){
               ans.push_back(-1);
            }
            else{
               ans.push_back(s.top().second);
            }            
        }
        s.push({v[i], i});
    }

    //reverse(ans.begin(), ans.end());
    for(int i = 0 ; i< ans.size(); i++){
        ans[i] = i - ans[i];
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
    int n;
    cin >> n;
    vector<int> inp;
    for (int i = 0; i < n; i++)
    {
        int temp ;
        cin>> temp;
        inp.push_back(temp);
    }
    vector<int> out = stock(inp);
    for(auto x:out){
        cout << x << " ";
    }
    cout << endl;
    
    }
    return 0;
}

