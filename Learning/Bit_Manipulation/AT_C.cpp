#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
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
void solve() {
    int n , m ;
    cin >> n >> m;
    int arr[n][m];
    int arr1[n][m];
    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j< m ; j++){
            int temp ; cin >> temp;
            arr1[i][j] = temp;
            arr[i][j] = temp%7;           
        }
    }
    bool ans  = true;
    for(int i = 0 ; i< m ; i++){
        for(int j = 1 ; j< n ; j++){
           if(arr[j][i] !=arr[j-1][i]) ans = false;
          
           if(arr1[j][i] !=arr1[j-1][i]+7) ans = false;
           // cerr << arr[j][i] << " ";
        }
       // cerr << endl;
    }
      for(int i = 0 ; i< n ; i++){
        for(int j = 1 ; j< m ; j++){
           if(arr1[i][j] !=arr1[i][j-1]+1) ans = false;
            if(arr[i][j] !=arr[i][j-1]+1) ans = false;
            
        }
    }

    if(ans){cout << "Yes" << endl;}
    else{cout << "No"<< endl;}


}
/*--------------------------------------------------------*/
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t=1;
	while (t--) {

		solve();

	}
	return 0;
}