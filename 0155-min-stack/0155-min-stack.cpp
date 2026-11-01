class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    
    }
    
    void push(int value) {
        st.push(value);

        if(minSt.size() > 0 && st.top() >= minSt.top()){
            minSt.push(minSt.top());
        }
        else{
            minSt.push(value);
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */