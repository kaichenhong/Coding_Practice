/**
 *  LeetCode: 232. Implement Queue using Stacks (Easy)
 *
 *      Implement the following operations of a queue using stacks.
 *
 *      push(x) -- Push element x to the back of queue.
 *      pop() -- Removes the element from in front of queue.
 *      peek() -- Get the front element.
 *      empty() -- Return whether the queue is empty.
 *
 *
 *      Example:    1. queue.push(1);
 *                     queue.push(2);  
 *                     queue.peek();  // returns 1
 *                     queue.pop();   // returns 1
 *                     queue.empty(); // returns false
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.8 MB [100.00%])
 */


class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        container.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = container.front();
        container.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return container.front();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (container.size()) ? false : true;
    }

    queue<int> container;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */