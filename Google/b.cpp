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

int solve() {

	int val = 0 , n ;
	string P;
	cin >> n >> P;
	int dp[3][n + 1];

	for (int i = 0 ; i < 3 ; i++) {
		dp[i][0] = 0;
	}

	for (int i = 1 ; i <= n ; i++) {
		char x = P[i - 1];
		if (x == 'U') {
			dp[0][i] = 0;
			dp[1][i] = 0;
			dp[2][i] = 0;
		}

		else if (x == 'R') {
			dp[0][i] = 1;
			dp[1][i] = 0;
			dp[2][i] = 0;
		}

		else if (x == 'Y') {
			dp[0][i] = 0;
			dp[1][i] = 1;
			dp[2][i] = 0;
		}

		else if (x == 'B') {
			dp[0][i] = 0;
			dp[1][i] = 0;
			dp[2][i] = 1;
		}

		else if (x == 'O') {
			dp[0][i] = 1;
			dp[1][i] = 1;
			dp[2][i] = 0;
		}

		else if (x == 'P') {
			dp[0][i] = 1;
			dp[1][i] = 0;
			dp[2][i] = 1;
		}

		else if (x == 'G') {
			dp[0][i] = 0;
			dp[1][i] = 1;
			dp[2][i] = 1;
		}

		else if (x == 'A') {
			dp[0][i] = 1;
			dp[1][i] = 1;
			dp[2][i] = 1;
		}

	}

	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j <= n ; j++) {
			// cerr << dp[i][j] << " " ;
			if (dp[i][j] == 0 && dp[i][j + 1] == 1) {

				val++;
			}
		}

		// cerr << endl;
	}

	return val;
}
/*--------------------------------------------------------*/
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t; cin >> t;
	int tt;
	tt = t;
	while (t--) {

		cout << "Case #" << tt - t << ": " << solve() << endl;

	}
	return 0;
}