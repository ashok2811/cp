class Solution {
public:
    int search(vector<int>& arr, int key) {
        
    int l = 0 ;
    int r = arr.size() -1;
    int next , prev;
    int N =arr.size();
    if(N==1){
        if(arr[0] ==key){
            return 1;
        }
        return 0;
    }

    while (l<=r)
    {   
        int mid = l + (r-l)/2 ;
                //If found
        if(arr[mid] == key){ 
            return true;}
        
        
        else if(arr[mid] <arr[r]){ // Arr[mid] is in second half
           if(key >arr[r] || key < arr[mid]){
            r = mid-1;
           }
           else{
               l = mid +1;
           }
        }
        
        else if(arr[mid] >arr[r]){ // Arr[mid] is in first half
            if(key <= arr[r] || key > arr[mid]){
                l = mid +1;
            }
            else{
                r =mid-1;
            }

        }
        else{// removing the duplicates from end to compare
            r--;
            
        }
        
    }
        //If not founf
    return false;
        
    }
};