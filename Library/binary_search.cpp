#include <bits/stdc++.h>
using namespace std;

int BS(vector<int> &arr, int key){
    int l = 0 ;
    int r = arr.size() -1;
    while (l<=r)
    {   
        int mid = l + (r-l)/2 ;
        if(key == arr[mid]){ return mid;}
        else if(key>arr[mid]){
            l = mid +1;
        }
        else{
            r = mid -1;
        }
    }
    return -1;
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif


int n ; 
cin >> n;
vector<int> arr;
for(int i = 0 ; i <n ; i++){
    int t ; cin >> t ;
    arr.push_back(t);
}

cout << BS(arr, 4)<<endl;

return 0;
}