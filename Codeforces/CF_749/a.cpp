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
bool isPrime(int n) {
	for (int i = 2 ; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve() {

	int n ; cin >> n;
	vector<int> v(n, 0);
	int sum = 0;
	int odd_idx;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i - 1];
		sum += v[i - 1];
		if (v[i - 1] % 2 == 1) {
			odd_idx = i;
		}
	}

	debug(odd_idx);

	if (sum % 2 == 1 && isPrime(sum)) {
		cout << n - 1 << endl;
		for (int i = 1 ; i <= n; i++) {
			if (odd_idx == i)continue;
			cout << i << " ";
		}
		cout << endl;
	}

	else {
		cout << n << endl;
		for (int i = 1 ; i <= n; i++) {
			cout << i << " ";
		}
		cout << endl;
	}


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