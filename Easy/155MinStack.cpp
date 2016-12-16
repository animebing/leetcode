// Based on the solution of gongruya 
// main another stack with same length, then these two stacks can have same operation
class MinStack {
private:
    stack<int> data;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if (min.empty()) min.push(x);
        else if (x < min.top()) min.push(x);
        else min.push(min.top());
    }
    
    void pop() {
        data.pop();
        min.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


// Based on the solution of zjchenRice 
// just push elements less than or equal to minimum to min stack, then we need to compare the data.top() and min.top()
// to decide whether we need min.pop()
void push(int x) {
        data.push(x);
        if (min.empty()) min.push(x);
        else if (x <= min.top()) min.push(x);
    }
    
void pop() {
        if (data.top() == min.top()) min.pop();
        data.pop();
    }