#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x << " " << x << endl;
#else
#define debug(x)
#endif
void _print(vector<int> v1) {
	cerr << "[ ";
	for (auto i : v1) {
		cerr << i << " ";
	}
	cerr << "]";
}

vector<int> maxSlidingWindow(vector<int>& nums, int n, int k) {
        vector<int> ans;
        int i = 0; int j = 0 ; 
        deque<int> dq;

        while(j<n){
           
            while(dq.size() > 0 && dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);

            if(j-i+1 < k){
                j++;
            }
            
            else if(j-i +1 ==k){
               
                ans.push_back(dq.front());

                if(nums[i] == dq.front()){
                    dq.pop_front();
                }

                j++;
                i++;
            }
            
        }     
     return ans;
}

int main(){
 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

int n,k; cin >> n >> k;
vector<int> v(n,0);
for (int i = 0; i < n; i++){
    cin >> v[i];
}
vector<int> ans = maxSlidingWindow(v, n, k);
for(auto x : ans){
    cout << x <<" ";
}
return 0;
}