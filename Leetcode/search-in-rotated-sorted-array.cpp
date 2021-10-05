/* Assume the array like this

            /
           /
          /
         /
                /
               /
              /
             /
*/

class Solution {
public:
    int search(vector<int>& arr, int key) {
        
    int l = 0 ;
    int r = arr.size() -1;
    int next , prev;
    int N =arr.size();
    while (l<=r)
    {   
        int mid = l + (r-l)/2 ;
        next = (mid + 1) % N;
        prev = (mid + N -1) % N;
        
        //If found
        if(arr[mid] == key){ 
            return mid;}
        
        
        else if(arr[mid] <=arr[N-1]){ // Arr[mid] is in second half
           if(key >arr[N-1] || key < arr[mid]){
            r = mid-1;
           }
           else{
               l = mid +1;
           }
        }
        
        else{ // Arr[mid] is in first half
            if(key <= arr[N-1] || key > arr[mid]){
                l = mid +1;
            }
            else{
                r =mid-1;
            }

        }
        
    }
        //If not founf
    return -1;
        
    }
};