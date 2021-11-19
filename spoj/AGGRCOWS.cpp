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
typedef long long ll;
typedef vector<int> vi;
#define Rep(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for(auto& a : x)
#define nl '\n'
#define ri(n) int n; scanf("%d", &n);
#define rll(n) ll n; scanf("%lld", &n);
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
/*--------------------------------------------------------*/
int barns , cows;
vector<int> barn;
bool isValid(int dist){
    int C = 1;
    int last = 0;
    for(int i = 1 ; i <barns; i++){
        if(barn[i] - barn[last]>= dist){
            C++;
            last = i;
        }

        if(C>=cows){
            return true;
        }
    }
    return false;
}

void solve() {
barn.clear();
cin >> barns >> cows;

for(int i = 1 ; i<=barns ; i++){
    int temp; cin >> temp; 
    barn.push_back(temp);
}

sort(all(barn));
_print(barn);
int l = 0 , r = barn[barns - 1], ans=1; 

while(l<=r){
    int mid = l + (r-l)/2;
    if(isValid(mid)){
        ans = mid;
        l =mid +1;
    }
    else {
        r = mid -1 ;
    }
}


cout << ans << endl;





}
/*--------------------------------------------------------*/
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t; cin >> t;
	while (t--) {

		solve();

	}
	return 0;
}