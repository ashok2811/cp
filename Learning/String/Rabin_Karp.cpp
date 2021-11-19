#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
/*--------------------------------------------------------*/
typedef long long int ll;
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
ll pw[1000001];

void init(string st) {
	ll p  = 31;
	ll p_power = 1 ;
	pw[0] = 1;
	dp[0] = (st[0] - 'a' + 1);

	for (int i = 1; i < (int)st.size(); ++i)
	{
		char ch = st[i];

		p_power = (p_power * p) % mod;
		pw[i] = p_power;
		dp[i] = (dp[i - 1] + (ch - 'a' + 1) * p_power) % mod;
	}
}

ll getHash(string st) {
	ll value = 0;
	ll p  = 31;
	ll p_power = 1 ;
	for (int i = 0; i < (int)st.size(); ++i)
	{
		char ch = st[i];
		value = (value + (ch - 'a' + 1) * p_power) % mod;
		p_power = (p_power * p) % mod;
	}
	return value;
}

bool pattern_p_Hash(ll patternHash, int l, int r) {

	ll num1 = (patternHash * pw[l]) % mod;
	ll num2 = (dp[r] - dp[l - 1] + mod) % mod;

	if (num1 == num2) return true;
	return false;

}
/*--------------------------------------------------------*/
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif


	string text, pattern;
	int n , L , R;
	while (cin >> n) {
		cin >> pattern >> text;
		ll patternHash = getHash(pattern);
		init(text);
		for (L = 0, R = (int)pattern.size() - 1; R < (int)text.size(); L++, R++) {
			if (pattern_p_Hash(patternHash, L , R)) {
				cout << L << endl;
			}
		}
		cout << endl;

	}
	return 0;
}