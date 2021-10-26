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
void solve() {
	//Take Input
	string s, t;
	cin >> s >> t;
	// Some initial Variables for running the loop ans answer;
	int i = 0 , j = 0 , ans = INT_MAX;
	int idx = -1;
	// Create a map to store the frequency of characters
	unordered_map<char , int> mp;
	// Fill the map with character frequency
	for (auto x : t) mp[x]++;

	int count = mp.size();
	//Start the sliding
	while (j < s.length()) {

		if (mp.find(s[j]) != mp.end()) {
			mp[s[j]]--;
			if (mp[s[j]] == 0) count--;
		}

		while (count == 0) {
			//ans = min(ans, j - i + 1);
			if (ans > j - i + 1) {
				ans =  j - i + 1;
				idx = i;
			}

			if (mp.find(s[i]) != mp.end()) {

				if (mp[s[i]] == 0) {
					count++;
				}
				mp[s[i]]++;
			}
			i++;
		}

		j++;
	}

	if (idx == -1) {
		cout << "" << endl;
	}

	else {
		cout << s.substr(idx, ans) << endl;
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
	solve();
	return 0;
}