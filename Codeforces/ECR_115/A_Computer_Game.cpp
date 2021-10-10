#include <bits/stdc++.h>
using namespace std;

int main(){

// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif

int t; cin >> t ;
while(t--){
int n; cin >> n ;
string s1 , s2 ;

cin>>s1>>s2;
bool flag = true;
for(int i = 0; i < n ; i++){
    if(s1[i] =='1' &&s2[i]=='1') flag = false;
    if(s1[0] == '1' || s2[n-1] == '1') flag = false;
}


if(flag){
    cout << "YES" << endl;
}
else{
    cout << "NO" << endl;
}

}


return 0;
}