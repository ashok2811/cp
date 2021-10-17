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
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
/*--------------------------------------------------------*/
void solve() {
	int a , b , c;
	cin >> a >> b >> c;
	int ans = 0;
	if (a == b) {
		ans = a;
	}

	else if (b == c) {
		ans = b;
	}

	else if (c == a) {
		ans = c;
	}

	else {
		int d , e , f;
		d = a - 1;
		e = b - 1;
		f = c + 2;
		if (d == e) {
			ans = d + 1;

		}

		else if (e == f) {
			ans = e + 1;

		}

		else if (f == d) {
			ans = f + 1;

		}

		d = a + 2;
		e = b - 1;
		f = c - 1;
		if (d == e) {
			ans = d + 1;

		}

		else if (e == f) {
			ans = e + 1;

		}

		else if (f == d) {
			ans = f + 1;

		}

		d = a - 1;
		e = b + 2;
		f = c - 1;
		if (d == e) {
			ans = d + 1;
		}

		else if (e == f) {

			ans = e + 1;
		}

		else if (f == d) {
			ans = f + 1;
		}

	}

	if (ans == 0) cout << -1 << nl;

	else cout << ans << nl;



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
	while (t--) {

		solve();

	}
	return 0;
}