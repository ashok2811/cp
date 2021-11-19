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
	int n , k ;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0 ; i < n; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
	}

	ll s = 0; int rem = k + 1;
	int i;
	for (i = 0 ; i < n - 1 ; i++) {
		int max_itake = pow(10 , v[i + 1] - v[i]) - 1 ;
		s = s + (ll)(min(rem, max_itake) * (pow(10, v[i])));
		rem = rem - min(rem, max_itake);
		if (rem <= 0) {
			break;
		}
	}

	s = s + (ll)(rem * (pow(10, v[i])));

	cout << s << endl;
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