class MinStack {
public:
    stack<long long> st;
    long long mini;
    long long x;

    MinStack() {
        // nothing to initialize here
    }
    
    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val > mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini);  // encode using long long
                mini = val;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        x = st.top();
        st.pop();
        if (x < mini) {
            mini = 2 * mini - x;  // decode the previous mini
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        x = st.top();
        return (x < mini) ? mini : x;
    }
    
    int getMin() {
        return mini;
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