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

	int n ; cin >> n ;
	vector<int> vone , vzero;
	for (int i = 0 ; i < n ; i++) {
		int temp; cin >> temp;
		if (i % 2 == 0) {
			vzero.pb(temp);
		}
		else {
			vone.pb(temp);
		}
	}

	sort(all(vone));
	sort(all(vzero) , greater<int>());


	vector<int> prefix(n / 2 , 0);
	prefix[0] = vzero[0];
	for (int i = 1 ; i < (n / 2) ; i++) {
		prefix[i] = prefix[i - 1] + vzero[i];
	}

	ll ans = 0;
	for (int i = 0 ; i < (n / 2); i++) {
		ans = ans + (ll)(vone[i] * prefix[i]);
	}


	cout << ans << endl;

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