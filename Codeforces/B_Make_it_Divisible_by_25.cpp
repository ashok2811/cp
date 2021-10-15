#include <bits/stdc++.h>

using namespace std;

vector<int> arr[10];
void solve() {
	for (int i = 0; i < 10; i++) arr[i].clear();
	long long n;
	cin >> n;

	int i = 0;
	while (n > 0LL) {
		int a = (int)(n % 10);
		n = n / 10;
		if (a == 0 || a == 2 || a == 5 || a == 7) {
			arr[a].push_back(i);
		}
		i++;
	}


	int ans = INT_MAX;

	if (arr[0].size() > 1) {
		int a = arr[0][1] - arr[0][0] - 1 + arr[0][0] ;
		ans = min(a, ans);
	}
	else if (arr[0].size() == 1) {
		if (arr[5][0] > arr[0][0]) {

			int a = arr[5][0] - arr[0][0] - 1 + arr[0][0] ;
			ans = min(a, ans);
		}
	}

	else if (arr[5].size() > 0) {
		int a = INT_MAX , b = INT_MAX ;
		if (arr[2][0] > arr[5][0]) {
			a = arr[2][0] - arr[5][0] - 1 + arr[5][0] ;
		}

		if (arr[7][0] > arr[5][0]) {
			b = arr[7][0] - arr[5][0] - 1 + arr[5][0] ;
		}
		ans = min(a, ans);
		ans = min(b, ans);
	}

	cout << ans << endl;

}

int main() {
	int t; cin >> t;
	while (t--) {

		solve();
	}

}