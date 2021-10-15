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

void solve() {
	int a , b , c;
	cin >> a >> b >> c;
	int mx = max(a , b);
	mx = max(mx , c);

	if (a == b && b == c) {
		cout << 1 << " " << 1 << " " << 1 << endl;
	}
	else {

		if (mx == a && (mx != b && mx != c)) {
			cout << 0 << " ";
		}
		else {
			cout << mx - a + 1 << " ";
		}

		if (mx == b && (mx != a && mx != c)) {
			cout << 0 << " ";
		}
		else {
			cout << mx - b + 1 << " ";
		}

		if (mx == c && (mx != b && mx != a)) {
			cout << 0 << endl;
		}
		else {
			cout << mx - c + 1 << endl;
		}
	}


}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t; cin >> t;
	while (t--) {
		solve();
	}

}