#include <bits/stdc++.h>
using namespace std;

int BS(vector<int> &arr, int key){
    int l = 0 ;
    int r = arr.size() -1;
    int next , prev;
    int N =arr.size();
    while (l<=r)
    {   
        int mid = l + (r-l)/2 ;
        next = (mid + 1) % N;
        prev = (mid + N -1) % N; 
        if(arr[mid] == key){ 
            return mid;}
        else if(arr[mid] <=arr[N-1]){
           if(key >arr[N-1] || key < arr[mid]){
            r = mid-1;
           }
           else{
               l = mid +1;
           }
        }
        else{
            if(key <= arr[N-1] || key > arr[mid]){
                l = mid +1;
            }
            else{
                r =mid-1;
            }

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

cout << BS(arr, 0)<<endl;

return 0;
}