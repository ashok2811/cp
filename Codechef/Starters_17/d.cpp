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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
/*--------------------------------------------------------*/

pair<int , int> inv(string s , int n) {
	vector<int> suff_zero(n + 1, 0);
	int val = 0 , zeros = 0;
	for (int i = n - 1 ; i >= 0 ; i--) {
		if (s[i] - '0' == 0) {
			zeros++;
			suff_zero[i] = suff_zero[i + 1] + 1;
		}

		else {
			suff_zero[i] = suff_zero[i + 1];
			val = val + suff_zero[i] ;
		}
	}

	return {val , zeros};
}

void solve() {
	int n , m ;
	cin >> n >> m ;
	priority_queue<pair<int , pair<string, int>>> pq;
	for (int i = 0 ; i < n ; i++) {
		string s ; cin >> s ;
		pair<int , int> pp;
		pp = inv(s , m) ;
		pq.push(make_pair(m - pp.second , make_pair(s , pp.first)));
	}
	int val = 0, last_zeros = 0, ones = 0 ;
	while (pq.size() > 0) {
		auto x = pq.top();

		ones = x.first ;
		val = val + x.second.second + ones * last_zeros;
		cerr << x.second.first << " " << x.second.second << " " << val << " " <<
		     last_zeros << " " << ones << endl;
		last_zeros += m - x.first;

		pq.pop();

	}
	//cerr << endl;
	cout << val << endl;

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