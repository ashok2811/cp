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
void solve() {
    string s;
    cin >> s;
    if(s[0]==s[1] && s[1]==s[2])cout << 1 << endl;

    else if(s[0]==s[1] || s[1]==s[2] || s[0]==s[2])cout << 3 << endl;


    else if(s[0]!=s[1] && s[1]!=s[2])cout << 6 << endl;
}
/*--------------------------------------------------------*/
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t=1;
	while (t--) {

		solve();

	}
	return 0;
}