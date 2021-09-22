class Solution {
public:
   int mah(vector<int> &v){
        int n = v.size();
        int L[n] , R[n];
        stack<int> st;

        // Implement nsr
        for (int i = 0; i <n; i++)
        {
            while (!st.empty() && (v[st.top()])>=(v[i]))
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
            while (!st.empty() && (v[st.top()])>=(v[i]))
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
            int area = (v[i])*width;
            mx_area = max(area, mx_area);
        }

    return mx_area;

}

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        
        int mx = INT_MIN;
        
        vector<vector<int>> temp(n);
        for(auto x: matrix[0]){
            temp[0].push_back(x-'0');
        }
        mx = max(mx, (int)mah(temp[0]));
       
        
        for(int i = 1; i<n; i++){
            for(int j = 0 ; j<m; j++){
                if(matrix[i][j]!='0'){
                    temp[i].push_back(temp[i-1][j] + matrix[i][j] -'0');
                }
                
                else{
                    temp[i].push_back(0);
                }
                
            }
            
            mx=max(mx, (int)mah(temp[i]));
            
        }
        
    return mx;
        
    }
};