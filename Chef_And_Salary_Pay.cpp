#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){

int t ; cin>>t;
while(t--){
    int X, Y;
    cin >> X>>Y;
    string s;
    cin >> s;
    int sal = 0;
    for(int i=0; i < 30; i++){
        if(s[i]-'0'==1){
            sal+=X;
        }
    }
   // cout << sal << endl;

    int bonus= 0 ;
    int ml = 0;
    int last = 0;

    for(int i=0; i < 30; i++){
        int j= 0;
       while(i + j < 30 && s[i + j] -'0' ==1){
           j++;
       }
       ml = max(ml, j);
       //i = i + j -1;
        
    }
    bonus = Y*ml; 
    cout << sal + bonus << endl;
}


return 0;
}