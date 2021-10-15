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
	int n, k ;
	cin >> n >> k;
	vi v(n + 1, 0);

	Rep(i , 0 , k) {
		int temp; cin >> temp;
		v[temp]++;
	}
	_print(v);
	cerr << endl;
	int tt = n - 1;
	int sum = 0;
	int i = 1;
	int mice = 0;

	while (sum <= tt && i <= tt) {

		if (v[n - i] > 0) {
			if (sum + v[n - i]*i) {
				sum = sum + v[n - i] * i;
				mice = mice + v[n - i];
				debug(sum);
				debug(i);
				debug(n - i);
				debug(v[n - i]);
			}

		}

		i++;

	}
	if (sum > tt) {
		if (tt != 1) {
			i--;
			sum = sum - v[n - i] * i;
			mice = mice - v[n - i];
			int aa = ((n - i) / (i));
			debug(aa);
			mice += aa;
		}
		else {
			mice = 1;
		}




	}

	cerr << endl;

	cout << mice << endl;







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

