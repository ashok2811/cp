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

