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
double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {

	if (arr1.size() > arr2.size()) {
		return findMedianSortedArrays(arr2, arr1);
	}
	int n1 = arr1.size();
	int n2 = arr2.size();

	int low = 0 ;
	int high = n1;

	while (low <= high) {
		int cut1 = (low + high) / 2;
		int cut2 = (n1 + n2 + 1) / 2 - cut1;

		//Initialise l1 ,l2 , r1, r2;
		int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
		int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1]; f
		int r1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
		int r2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

		if (l1 <= r2 && l2 <= r1) {
			if ((n1 + n2) % 2 == 0) {
				return (max(l1 , l2) + min(r1, r2)) / 2.0;
			}

			else {
				return max(l1, l2);
			}
		}

		else if (l1 > r2) {
			high = cut1 - 1;
		}

		else {
			low = cut1 + 1;
		}

	}
	return 0.0;

}


void solve() {

	int n1 , n2; cin >> n1 >> n2;
	vector<int> arr1(n1);
	vector<int> arr2(n2);
	for (int i = 0 ; i < n1 ; i++) {
		cin >> arr1[i];
	}
	for (int i = 0 ; i < n2 ; i++) {
		cin >> arr2[i];
	}

	cout << findMedianSortedArrays(arr1 , arr2) << endl;
}
/*--------------------------------------------------------*/
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t = 1;
	while (t--) {

		solve();

	}
	return 0;
}