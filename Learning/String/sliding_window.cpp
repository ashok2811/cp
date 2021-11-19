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
string text , pattern;
int tl , pl;
void solve() {
	getline(cin, text);
	getline(cin , pattern);

	tl = text.length();
	pl = pattern.length();
	// Time Complexity : O((TL-PL + 1)*PL)
	// Space Complexity: O(1)

	for (int l = 0 ; l <= tl - pl ; l++) { // TL - PL
		int cnt = 0;
		for (int r = l; r - l < pl ; r++) { // PL
			if (text[r] == pattern[r - l]) {
				cnt++;
				if (cnt == pl) {
					cout << l << " ";
				}
			}
			else break;
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
	int t; cin >> t;
	cin.ignore();
	while (t--) {

		solve();

	}
	return 0;
}