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

unordered_map<ll, ll > mm;
void solve() {

	int n , m ;
	cin >> n >> m ;
	for (int i = 0 ; i < n ; i++) {
		int temp; cin >> temp;
		mm[temp]++;
	}
	ll ans = 0 ;
	for (int i = 0 ; i < m ; i++)
	{
		int temp; cin >> temp;
		ans += mm[temp];
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
	int t = 1;
	while (t--) {

		solve();

	}
	return 0;
}