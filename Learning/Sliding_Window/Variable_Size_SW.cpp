#include <bits/stdc++.h>
using namespace std;
void _print(vector<int> v1) {
	cerr << "[ ";
	for (auto i : v1) {
		cerr << i << " ";
	}
	cerr << "]";
}

int solve(vector<int> &nums, int sum, int size){
    int i = 0, j = 0, ans = -1;
    int k = 0;
    while(j<size){
        if(k<sum){
            k+=nums[j];
            j++;
        }

        else if(k == sum){
            ans = max(ans, j-i + 1);
            k+=nums[j];
            j++;
        }
        else if(k>sum){
            while(k>sum){
                k -=nums[i];
                i++;
            }

        }
    }
    return ans;
}


int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

vector<int> nums; int sum, size;
cin >> size >> sum;

for(int i = 0 ; i < size; i ++){
    int temp; cin>>temp;
    nums.push_back(temp);
}

_print(nums);

cout << solve(nums, sum, size);

    return 0;
}  