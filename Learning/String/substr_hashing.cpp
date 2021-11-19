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
typedef long long int ll;
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
#define mod 1000000007
/*--------------------------------------------------------*/
ll power(ll a, ll n , ll m) {
	ll res = 1 ;
	while (n > 0) {
		if (n & 1) res = (res * a) % m;
		n >>= 1;
		a = (a * a) % m;
	}
	return res;
}

ll dp[1000001];
ll inv[1000001];

void init(string st) {
	ll p  = 31;
	ll p_power = 1 ;
	inv[0] = 1;
	dp[0] = (st[0] - 'a' + 1);

	for (int i = 0; i < (int)st.size(); ++i)
	{
		char ch = st[i];

		p_power = (p_power * p) % mod;
		inv[i] = power(p_power, mod - 2 , mod);//using Fermet's Little Theorem
		dp[i] = (dp[i - 1] + (ch - 'a' + 1) * p_power) % mod;
	}
}

ll solve(int l, int r ) {

	ll res = dp[r];
	if (l > 0LL) res -= dp[l - 1];

	res  = (res * inv[l]) % mod;

	return res;

}
/*--------------------------------------------------------*/
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif


	string inp_string;

	cin >> inp_string;
	init(inp_string);
	int t; cin >> t;
	int L, R;
	while (t--) {
		cin >> L >> R;
		cout << solve(L, R) << endl;

	}
	return 0;
}