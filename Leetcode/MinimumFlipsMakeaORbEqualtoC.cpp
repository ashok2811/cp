    class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0 ; // variable to store final result
        for(int i = 0 ; i< 32; i++){ //Run a loop for 32 times because we are dealing with 32 bit int
            bool x=0, y=0, z=0; 
            int b1 = 1, b2 =1, b3 =1;
			// Checking if ith bit is set in a, b , c
            if(a & (b1<<i)) x = true;
            if(b & (b2<<i)) y = true;
            if(c & (b3<<i)) z = true;
            if(!z){ // if i th bit is not set in c that imples we need to flip all ones in a or b to 0
                if(x) cnt++;
                if(y) cnt++;
            }
            else{ // if ith bit in c is set, we need to only check if both a, b ith bit is not set
                if(!x && !y) cnt++;
            }
        }
       return cnt ; 
    }
};