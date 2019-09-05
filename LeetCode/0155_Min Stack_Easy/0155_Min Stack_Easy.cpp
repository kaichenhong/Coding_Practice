/**
 *  LeetCode: 155. Min Stack (Easy)
 *
 *      Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 *      push(x) -- Push element x onto stack.
 *      pop() -- Removes the element on top of the stack.
 *      top() -- Get the top element.
 *      getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *      Example:    push(-2);   push(0);    push(-3);   getMin(); --> Returns -3;   pop();  top(); --> Returns 0;   getMin(); --> Returns -2;
 *
 *
 *
 *  Results:    AC (28 ms [90.46%];  16.7 MB [100.00%])
 */


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        nums.push(x);
        if (minBuff.size() == 0 || x <= minBuff.top()) {
            minBuff.push(x);
        }
    }
    
    void pop() {
        int topValue = nums.top();
        nums.pop();
        if (topValue == minBuff.top()) {
            minBuff.pop();
        }
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return minBuff.top();
    }

private:
    stack<int> nums, minBuff;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */