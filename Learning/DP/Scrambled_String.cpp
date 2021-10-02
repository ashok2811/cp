#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
bool solve(string a, string b){

    // base
    if(a.compare(b)==0) return true;
    if(a.length()<=1) return false;

    //memo
    string key = a;
    key.push_back('_');
    key.append(b);

    if(mp.find(key)!=mp.end()) return mp[key];
    
    int n = a.length();
    bool flag = false;

    for(int i =1 ; i <= n-1 ; i++){
        
        if(( // swap
            solve(a.substr(0,i) , b.substr(n-i, i)) &&
            solve(a.substr(i , n-i) , b.substr(0 , n-1))
        )

        ||( //No Swap
            solve(a.substr(0,i) , b.substr(0, i)) &&
            solve(a.substr(i , n-i) , b.substr(i , n-1))
        )){
            flag = true;
            break;
        }

    }
  

    // store 
    mp[key] = flag;

    // return 

    return flag;

}

int main() {
    mp.clear();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string a , b ;
    cin >> a >> b ; 

    if(a.length()!=b.length()){
        cout << false << endl;
    }
    else if(a.empty() && b.empty()){
        cout << true << endl;
    }

    else{
        cout << solve(a , b)<< endl;
    }
    
    return 0;
}

