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
/*--------------------------------------------------------*/
typedef long long ll;
typedef vector<int> vi;
#define Rep(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for(auto& a : x)
#define nl '\n'
#define ri(n) int n; scanf("%d", &n);
#define rll(n) ll n; scanf("%lld", &n);
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
/*--------------------------------------------------------*/

int solve() {
	set<array<char, 2>> U = {{'O', 'R'}, {'O', 'Y'}, {'P', 'R'}, {'P', 'B'}, {'G', 'Y'}, {'G', 'B'}};


	int ans = 0;
	int n;
	string s;
	cin >> n >> s;

	for (auto x : {'R', 'Y', 'B'}) {
		int prv = 0;
		for (auto e : s) {
			int nx = 0;
			if (e == x || e == 'A' || U.find({e, x}) != U.end()) {
				nx = 1;
			}
			if (prv != nx) {
				ans += prv;
				prv = nx;
			}
		}
		ans += prv;
	}
	return ans;
}
/*--------------------------------------------------------*/
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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