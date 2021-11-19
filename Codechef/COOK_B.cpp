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
	vector<int> v;
	for (int i = 0 ; i < n ; i++) {
		int temp; cin >> temp ;
		v.pb(temp);
	}

	int gr = 0 , ls = 0 ;
	int cnt = 0 ;

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			if (v[i] >= v[j]) {
				if (i != j)gr++;
			}
			else {
				if (i != j)ls++;
			}
		}
		if (gr >= ls)cnt++;
		gr = 0; ls = 0;
	}

	cout << cnt << endl;


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