#include <bits/stdc++.h>

using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x << " " << x << endl;
#else
#define debug(x)
#endif

void _print(vector<int> v1) {
	cerr << "[ ";
	for (int i : v1) {
		cerr << i << " ";
	}
	cerr << "]";
}


int n ;
string s;
bool prime[100];

void primes() {
	for (int i = 2; i < 100; i++) {
		prime[i] = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				prime[i] = false;
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n ; i++) {
		if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
			cout << 1 << endl;
			cout << s[i] << endl;
			return;
		}
	}

	for (int i = 0 ; i < n ; i++) {
		for (int j = i + 1; j < n ; j++) {
			if (!prime[(s[i] - '0') * 10 + (s[j] - '0')]) {
				cout << 2 << endl;
				cout << s[i] << s[j] << endl;
				return;
			}
		}
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	primes();
	int t; cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		solve();
		debug(n);
	}

}