#include <bits/stdc++.h>
using namespace std;

int solve(string s1, string s2){
    int n = s1.length();
    int k = s2.length();
    unordered_map<char, int> m;
     
    for(int i = 0 ; i< k ; i++){
        m[s2[i]]++;
    }
    int cnt = m.size();
    int i = 0, j = 0;
    int anagrams = 0;
    while(j<n){

        if(m.find(s1[j])!=m.end()){
            m[s1[j]]--;
            if(m[s1[j]]==0){
                cnt--;
            }
        }

        if(j-i+1 <k){
            j++;
        }
        else if(j-i +1==k){
            
            if(cnt==0){
            anagrams++;
            cout << i << endl;
              }

            if(m.find(s1[i])!=m.end()){
                m[s1[i]]++;
                if(m[s1[i]]==1) cnt++;
            }

            //slide the window
            j++;
            i++;
        }
    }
return anagrams;
    
}



int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

string s1, s2;
cin>>s1>>s2;

cout << solve(s1, s2)<<endl;
return 0;
}