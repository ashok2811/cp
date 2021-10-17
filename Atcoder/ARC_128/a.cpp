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
	int N ; cin >> N;
	vector<int> v;
	for (int i = 0 ; i < N; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
	}
	bool taken  = false;
	for (int i = 0 ; i < N - 1; i++) {
		if (v[i] > v[i + 1] && taken == false) {
			cout << 1 << " ";
			taken = true;

		}

		else if (v[i] <= v[i + 1] && taken == true) {
			cout << 1 << " ";
			taken = false;
		}
		else {
			cout << 0 << " ";
		}

		if (v[i] <= v[i + 1] && i == N - 2) {
			cout << 0 << " ";
		}

		if (taken == true && i == N - 2) {
			cout << 1 << " ";
			taken  = false;
		}

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
	int t = 1;
	while (t--) {

		solve();

	}
	return 0;
}