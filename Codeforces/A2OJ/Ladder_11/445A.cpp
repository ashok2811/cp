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

char arr[101][101];
int vis[101][101];
int N, M;

int dx[] = { -1, 0 , 1 , 0};
int dy[] = {0, -1 , 0 , 1};

bool isValid(int i , int j) {
	if (i < 1 || i > N || j < 1 || j > M) return false;
	if (arr[i][j] == '-') return false;
	return true;
}


void dfs(int i , int  j , bool col) {
	vis[i][j] = 1;
	for (int k = 0 ; k < 4 ; k ++) {
		if (isValid(i + dx[k] , j + dy[k]) && !vis[i + dx[k]][j + dy[k]]) {
			dfs(i + dx[k] , j + dy[k] , col ^ 1);
		}
	}
	if (col == 1) arr[i][j] = 'W';
	else if (col == 0) arr[i][j] = 'B';
}


void solve() {

	cin >> N >> M ;
	for (int i = 1 ; i <= N ; i++ ) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1 ; i <= N ; i++ ) {
		for (int j = 1; j <= M; j++) {
			if (isValid(i , j) && !vis[i][j]) {
				dfs(i , j , 0);
			}
		}
	}

	for (int i = 1 ; i <= N ; i++ ) {
		for (int j = 1; j <= M; j++) {
			cout << arr[i][j];
		}
		cout << endl;
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
	int t = 1;
	while (t--) {

		solve();

	}
	return 0;
}