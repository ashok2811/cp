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

int solve(vector<int> &nums, int sum, int size) {
    int i = 0, j = 0, ans = -1;
    int k = 0;
    while (j < size) {

        k += nums[j];
        if (k < sum) {// Hit sum barrier
            j++;
        }

        else if (k == sum) { // Found a window having intended sum
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (k > sum) {

            while (k > sum ) {
                k -= nums[i]; // Remove & Slide
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

    vector<int> nums; int sum, size;
    cin >> size >> sum;

    for (int i = 0 ; i < size; i ++) {
        int temp; cin >> temp;
        nums.push_back(temp);
    }

    cout << solve(nums, sum, size);

    return 0;
}