#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n;
		cin >> n ;
		cout << (n - 1) * (n - 2) + 1 << endl;
	}
	return 0;
}