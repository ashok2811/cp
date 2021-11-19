class Solution {
public:
    
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

    
    
    
    int largestRectangleArea(vector<int>& inp) {
        
    vector<int> out1 = nsl(inp);
    vector<int> out2 = nsr(inp);
        int mx = INT_MIN;
    for(int i = 0 ; i <out1.size(); i++){
        mx = max((out2[i] - out1[i]- 1)*inp[i] , mx );
    }
    
     return mx;   
    }
};



// Optimised

#include <bits/stdc++.h>
using namespace std;

int mah(vector<int> &v){
        int n = v.size();
        int L[n] , R[n];
        stack<int> st;

        // Implement nsr
        for (int i = 0; i <n; i++)
        {
            while (!st.empty() && v[st.top()]>=v[i])
            {
                st.pop();
            }
            if(st.empty()){
                L[i] = -1;
            }
            else{
                L[i] = st.top();
            }
            st.push(i);
            
        }
        


        //Clear Stack
        while(st.empty()==false){
            st.pop();
        }
        //Implement nsl

        for (int i = n-1; i >=0; i--)
        {
            while (!st.empty() && v[st.top()]>=v[i])
            {
                st.pop();
            }
            if(st.empty()){
                R[i] = n;
            }
            else{
                R[i] = st.top();
            }
            st.push(i);
            
        }

        int mx_area = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            // Calculating the maximum area.
            int width = R[i] - L[i] - 1;
            int area = v[i]*width;
            mx_area = max(area, mx_area);
        }

    return mx_area;

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

    int ans = mah(inp);

    cout << ans << endl;
    
    }
    return 0;
}

