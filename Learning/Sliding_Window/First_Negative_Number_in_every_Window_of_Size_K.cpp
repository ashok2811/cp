#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>&v, int n , int k){
    int i = 0, j = 0;
    queue<int> q;
    while(j<n){
        if(v[j]<0){
            q.push(v[j]);
        }        
        if(j-i+1 <k){
            j++;
        }
        else if(j-i +1==k){
            if(!q.empty()){
                int front = q.front();
                if(front == v[i]){ 
                    q.pop();
                }
                cout << front << " ";
            }
            else{
                cout << 0 << " ";
            }

            //slide the window
            j++;
            i++;
        }
    }

    
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
solve(v, n, k);
return 0;
}