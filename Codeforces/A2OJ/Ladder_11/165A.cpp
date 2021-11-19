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
	int n ; cin >> n;
	map<int , pair<int, int>> row;
	map<int , pair<int, int>> col;
	int count = 0;
	vector<pair<int , int>> points;
	for (int i = 0; i < n ; i++) {
		int a , b ;
		cin >> a >> b;
		points.push_back({a, b});
		row[b] = {1001, -1001};
		col[a] = {1001 , -1001};

	}

	for (auto x : points) {
		row[x.s] = {min(row[x.s].f , x.f) , max(row[x.s].s, x.f)} ;
		col[x.f] = {min(col[x.f].f , x.s) , max(col[x.f].s, x.s)} ;

	}

	for (auto x : points) {

		if ((x.f > row[x.s].f && x.f < row[x.s].s) &&
		        (x.s > col[x.f].f && x.s < col[x.f].s)) {
			count ++;
		}
	}

	cout << count << endl;
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

