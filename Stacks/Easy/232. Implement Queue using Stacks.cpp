// Time Complexity: O(n) for peek
// Space Complexity: O(1) as using two stacks is given in the question, apart from that
// no extra space is used

class MyQueue {
    stack<int> enqueue;
    stack<int> dequeue;
public:
    MyQueue() {}

    void push(int x) {
        enqueue.push(x);
    }

    int pop() {
        int front = peek();
        dequeue.pop();
        return front;
    }

    int peek() {
        // if dequeue is empty then put all enqueue elements in it
        // enqueue is now empty but it doesn't matter
        // we will push to enqueue, and peek and pop from dequeue now
        // after continuous popping dequeue will again be empty, at that time push
        // all enqueue elements into dequeue again
        if(dequeue.empty()) {
            while(!enqueue.empty())
                dequeue.push(enqueue.top()), enqueue.pop();
        }

        return dequeue.top();
    }

    bool empty() {
        return enqueue.empty() && dequeue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
