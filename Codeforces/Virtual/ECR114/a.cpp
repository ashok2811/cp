/*____________________________Definitions__________________________*/
#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
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

int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int T; cin >> T;
    while (T--) {
         int n ;
         cin >> n ;
         char arr[2*n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = '(';
            arr[2*n-1 - i] = ')';
        }
        
        for (int i = 0; i < 2*n; i++)
        {
            cout << arr[i];
        }
        cout << endl;
        
        for (int i = 1; i < n; i++)
        {   
            for (int j = 0; j <2*n; j++)
            {   
                if(j == i){
                    cout << ')';
                }
                else if(j==2*n-1-i){
                    cout << '(';
                }
                else{
                    cout << arr[j];
                }
            }

            cout << endl;
            
        }
        
        
    }
    return 0;
}
