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
<<<<<<< HEAD
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
=======
    int count = INT_MAX ;
    char ch = 'a';
    int imp = 0;

    for (int i = 0; i < 26; ++i)
    {
        int l = 0 , r = n - 1 , cnt = 0;

        while (l < r) {

            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else if (s[l] == ch + i) {
                if (s[l + 1] == s[r]) {
                    cnt++;
                    l++;
                }
            }

            else if (s[r] == ch + i) {
                if (s[r - 1] == s[l]) {
                    cnt++;
                    r--;
                }

            }
            else {
                imp++;
                break;
            }
            count = min(cnt, count);
        }

        if (imp == 26) {
            cout << -1 << endl;
        }
        else {
            cout << count << endl;
        }
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
>>>>>>> main
