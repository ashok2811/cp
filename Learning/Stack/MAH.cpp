#include <bits/stdc++.h>
using namespace std;

vector<int> nsr(vector<int> &v){
    vector<int> ans;
    stack<pair<int,int>> s;
    

    for(int x = v.size()-1; x>=0; x--){
        
        if(s.size()==0){
          ans.push_back(v.size());
        }
        else if(s.size()>0 && v[x] > (int)s.top().first){
            ans.push_back(s.top().second);
        }

        else if(s.size()>0 && v[x] <= (int)s.top().first){
            while(s.size()>0 && s.top().first>=v[x]){
                s.pop();
            }

            if(s.size()==0){
                ans.push_back(v.size());
            }

            else{
                ans.push_back(s.top().second);
            }
        }
        s.push({v[x], x});
    }
    
    reverse(ans.begin(), ans.end());

    return ans;
} 


vector<int> nsl(vector<int> &v){
    vector<int> ans;
    stack<pair<int,int>> s;
    

    for(int x = 0 ; x< v.size(); x++){
        
        if(s.size()==0){
          ans.push_back(-1);
        }
        else if(s.size()>0 && v[x] > (int)s.top().first){
            ans.push_back(s.top().second);
        }

        else if(s.size()>0 && v[x]  <= (int)s.top().first){
            while(s.size()>0 && s.top().first>=v[x] ){
                s.pop();
            }

            if(s.size()==0){
                ans.push_back(-1);
            }

            else{
                ans.push_back(s.top().second);
            }
        }
        s.push({v[x], x });
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
    vector<int> out1 = nsl(inp);
    vector<int> out2 = nsr(inp);
    for(int i = 0 ; i <out1.size(); i++){
        cout << (out2[i] - out1[i]- 1)*inp[i] << " ";
    }
    cout << endl;
    
    }
    return 0;
}

