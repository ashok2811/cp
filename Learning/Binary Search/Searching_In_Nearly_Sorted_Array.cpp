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

int BS(int arr[], int l, int r, int key) {

	while (r >= l) {
		int mid = l + (r - l) / 2 ;
		if (key == arr[mid]) return mid;
		if (mid - 1 >= l && key == arr[mid - 1]) return mid - 1;
		if (mid + 1 <= r && key == arr[mid + 1]) return mid + 1;
		if (key < arr[mid]) {
			r = mid - 2;
		}
		else if (key > arr[mid]) {
			l = mid + 2;
		}
	}
	return -1;
}

void solve() {

	int n, key; cin >> n >> key;
	int arr[n] ;
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	cout << BS(arr, 0, n - 1 , key) << endl;

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