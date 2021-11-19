class StockSpanner {
public:
    
    stack<pair<int, int>> s;
    int i ;
    StockSpanner() {
        s.push({INT_MIN, 0});
        i =1;
    }

    int next(int price) {
         if(s.empty())
        {   s.push({price,i});
            i++;
            return i-1;
        }
        else if(!s.empty() && s.top().first<=price){
            
            while (!s.empty() && s.top().first<=price)
            {
                s.pop();
            }
            
            if(s.empty())
            {
                s.push({price,i});
                i++;
                return i-1;
            }else{
                int ans=i-s.top().second;
                s.push({price,i});
                    i++;
                return ans;
            }
            
        }
         
        else{
            int ans = i - s.top().second;
            s.push({price,i});
            i++;
            return ans;
        }
        
    }
        
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */