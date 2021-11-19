#include <bits/stdc++.h>
using namespace std;

int main(){

// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif

int t; cin >> t;

while (t--){
    int n , k;
    cin >> n >> k;

   vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = i;
		}
		sort(v.begin(), v.end());
		int ans = 1;
		for (int i = 1; i < n; i++)
			if (v[i - 1].second + 1 != v[i].second)
				ans++;
		cout << (ans <= k ? "Yes" : "No") << endl;   
    

}



return 0;
}