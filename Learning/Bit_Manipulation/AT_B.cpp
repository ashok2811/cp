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
   int n;
   cin >> n ;
   unordered_map<int, int> m;
   for(int i = 0 ; i < n-1 ; i++){
       int a , b;
       cin >> a >> b ;
       m[a]++;
       m[b]++;
   }
   bool ans = false;
   for(auto x : m){
      // debug(x.second);
       if(x.second==n-1) ans = true;
   }

  if(ans) cout << "Yes" <<endl;
  else{cout << "No" <<endl;}
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