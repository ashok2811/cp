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

int Ceil(int arr[] , int l , int r , int key) {
	int res = INT_MAX;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (key == arr[mid]) return arr[mid];
		if (key > arr[mid]) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
			res = arr[mid];
		}
	}

	return res;
}



int Floor(int arr[] , int l , int r , int key) {
	int res = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (key == arr[mid]) return arr[mid];
		if (key > arr[mid]) {
			l = mid + 1;
			res = arr[mid];
		}
		else {
			r = mid - 1;
		}
	}

	return res;
}


void solve() {

	int n, key; cin >> n >> key;
	int arr[n] ;
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	cout << "Floor: " <<  Floor(arr, 0, n - 1 , key) << endl;
	cout << "Ceil: " << Ceil(arr, 0, n - 1 , key) << endl;

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