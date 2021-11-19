class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> st;
    long minE;
    MinStack() {
    }
    
    void push(int val) {
        if(st.size()==0){
            st.push(val);
            minE = val;
        }
        else{
            if(val>=(int)minE){
                st.push(val);
            }
            else{
                st.push((long)2*val - minE);
                minE=val;
            }
        }
        
    }
    
    void pop() {
         if(st.top()>=(int)minE){
             st.pop();
         }
        else{
            minE=(long)2*minE - (long)st.top();
            st.pop();
        }
    }
    
    int top() {
        
        if(st.top()>=(int)minE){
            return st.top();
         }
        
         return minE;
    
        
    }
    
    int getMin() {
        return minE;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */