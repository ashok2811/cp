#include <bits/stdc++.h>
using namespace std;
void _print(vector<int> v1) {
    cerr << "[ ";
    for (auto i : v1) {
        cerr << i << " ";
    }
    cerr << "]";
}
#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x << " " << x << endl;
#else
#define debug(x)
#endif

int solve(string &s, int k) {
    int i = 0, j = 0, ans = -1;
    int size = s.length();
    unordered_map<char, int> mp;

    while ( j < size) {

        mp[s[j]]++;
        if (mp.size() < k ) {// Hit the size
            j++;
        }

        else if (mp.size() == k ) { // Found a window having intended unique chars
            ans = max(ans, j - i + 1);
            cerr
            j++;
        }
        else if (mp.size() > k ) {

            while (mp.size() > k ) {
                mp[s[i]]--; // Remove & Slide
                if (mp[s[i]] == 0) { // If size == 0 , remove the element
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;  // Slide
        }
    }
    return ans;
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int k; cin >> k;
    string s ; cin >> s;
    cout << solve(s, k);

    return 0;
}