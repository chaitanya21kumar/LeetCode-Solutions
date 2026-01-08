class MinStack {
public:
    typedef long long int ll;
    stack<long long int> st;
    long long int mn=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {

        if(st.empty()){
            st.push(val);
            mn=val;
        }
        else{
            if(mn>val){
                long long int x=(ll)2*val-1LL*mn;
                st.push(x);
                mn=val;
            }
            else{
                st.push(val);
            }
        }
        
    }
    
    void pop() {

        ll x=st.top();
        st.pop();
        if(x<mn){
            mn=2*mn-x;
        }

        
    }
    
    int top() {

        ll x=st.top();
        if(x<mn) return mn;
        return x;
        
    }
    
    int getMin() {

        return mn;
        
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