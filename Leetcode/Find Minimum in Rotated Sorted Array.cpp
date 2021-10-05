class Solution {
public:
    

    
    int findMin(vector<int>& arr) {
        
        int l = 0 ;
    int r = arr.size() -1;
    int next , prev;
    int N =arr.size();
    while (l<=r)
    {   
        int mid = l + (r-l)/2 ;
        next = (mid + 1) % N;
        prev = (mid + N -1) % N; 
        if(arr[mid]<= arr[prev] && arr[mid] <= arr[next]){ 
            return arr[mid];}
        else if(arr[mid] >= arr[0]){
            l = mid +1;
        }
        else if(arr[mid] <= arr[N-1]){
            r = mid -1;
        }
    }
    return arr[0];
        
    }
};