#include <bits/stdc++.h>
using namespace std;
int arr[1001][6];


int main(){


int t; cin >> t ;
while(t--){
int n; cin >> n ;

for(int i =0; i<n; i++){
    for(int j=0 ; j<5; j++){
        cin>>arr[i][j];
         
    }
    
}

bool flag = false;
for(int i =0; i<5; i++){
    for(int j=i+1 ; j<5; j++){
        int d1 = 0, d2 =0,d3 =0;
        for(int k = 0 ; k<n ; k++){
            if(arr[k][i] && arr[k][j]) d3++;
            else if(arr[k][i]) d1++;
            else if(arr[k][j]) d2++;
        } 
        if(d1 <= n/2 && d2 <= n/2 && d1 +d2 + d3 ==n){
            flag =true;
        }
    }
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