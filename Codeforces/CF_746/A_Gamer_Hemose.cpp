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
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int T; cin >> T;
    while (T--) {

          int n , H;
          cin >> n>>H;
          vector<int> weapon;
          for(int i = 0 ; i < n ; i++){
              int temp;
              cin >> temp;
              weapon.push_back(temp);
          } 
          sort(weapon.begin(), weapon.end());
          
          int q , r;
          if(H<=weapon[n-1]){
              cout << 1 << endl;
          }
          else{
               q = H / (weapon[n-1] + weapon[n-2]);
               r = H % (weapon[n-1] + weapon[n-2]);

               if(r==0){
                   cout << 2*q << endl;
               }
               else if(r<=weapon[n-1]){
                   cout << 2*q +1 << endl;
               }
               else{
                   cout << 2*q +2 << endl;
               }

          }

         
    }
    return 0;
}

