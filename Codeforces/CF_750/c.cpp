#include <bits/stdc++.h>
using namespace std;

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

void solve(string s, int n) {
    int ans = n + 1;
    for (int c = 0; c < 26; ++c) {
        int l = 0, r = n - 1, cnt = 0;
        while (l <= r) {
            if (s[l] == s[r]) {
                l++, r--;
            }
            else if (s[l] == char('a' + c)) {
                cnt++, l++;
            }
            else if (s[r] == char('a' + c)) {
                cnt++, r--;
            }
            else {
                cnt = n + 1;
                break;
            }
        }
        ans = min(ans, cnt);
    }
    if (ans == n + 1) ans = -1;
    cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int T; cin >> T;
    while (T--)
    {   int n; cin >> n;
        string x ;
        cin >> x;
        solve(x , n);

    }


}