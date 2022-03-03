class MinStack {
    stack<long long> st; 
    long long mini; 
public:
//time=O(1)
//space =O(N) storing single elemnt in stack
    /** initialize your data structure here. */
    MinStack() {
        while(st.empty() == false) st.pop(); 
        mini = INT_MAX; 
    }
    
    void push(int value) {
        long long val = value; 
        if(st.empty()) {//if empty
            mini = val;  //initilize the mini val to that & push it
            st.push(val); 
        }
        else {
            if(val < mini) { //insert modified value
                st.push(2 * val * 1LL - mini);
                mini = val; //mini has to be updated
            }
            else {//if greatter dont need to do anything
                st.push(val); 
            }
        }
    }
    
    void pop() {
        if(st.empty()) return; 
        long long el = st.top(); 
        st.pop(); 
        
        if(el < mini) {//if modified value,rollback to minimal
            mini = 2 * mini - el; 
        }
    }
    
    int top() {
        if(st.empty()) return -1; 
        //check if modified value,mini has to be top value
        long long el = st.top(); 
        if(el < mini) return mini; 
        return el; //if not ,whatever at top of stack will be mini
    }
    
    int getMin() {
        return mini; //just return it will be stored in mini variable
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