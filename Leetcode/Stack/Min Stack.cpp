// https://leetcode.com/problems/min-stack/


class MinStack {
public:
    stack<int> st;
    stack<int> min_st;    // another stack to store the minimum elements in order
    void push(int val) {
        if(min_st.empty() or val < min_st.top()){
            min_st.push(val);   // only push the curr ele if it is the minimum
        }
        else min_st.push(min_st.top());     // or else duplicate the curr minimum so that the 2 stacks will stay at the same level
        st.push(val);
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
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
