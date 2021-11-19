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

vector<string> isOk = {"00", "25", "75", "50"};

void solve() {
	string s; cin >> s;
	int n = s.length();
	int ans = n;
	for (int i = 0 ; i < 4; i++) {
		for (int j = n - 1; j > 0; j--) {
			for (int k = j - 1; k >= 0; k--) {
				string ss = "";
				ss.push_back(s[k]);
				ss.push_back(s[j]);
				if (ss == isOk[i]) {
					debug(ss);
					ans = min(ans, n - k - 2 );
				}
			}

		}

	}
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t; cin >> t;
	while (t--) {
		cerr << endl;
		debug(t);
		solve();
	}

}