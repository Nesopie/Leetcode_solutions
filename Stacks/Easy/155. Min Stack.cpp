// Time Complexity: O(1)
// Space Complexity: O(n) (for the extra value in the pair)

class MinStack {
    vector<pair<int,int> > stack;
public:
    MinStack() {}

    void push(int val) {
        if(stack.empty())
            stack.push_back(make_pair(val,val));
        else
            stack.push_back(make_pair(val, min(stack.back().second, val)));
    }x

    void pop() {
        stack.pop_back();
    }

    int top() {
        return stack.back().first;
    }

    int getMin() {
        return stack.back().second;
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

// Two stack solution
// Time complexity: O(1)
// Space complexity: O(n) worst case every new value is min so s2's size is equal to s1

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MinStack() {}

    void push(int val) {
        s1.push(val);
        if(s2.empty() || val <= getMin())
            s2.push(val);
    }

    void pop() {
        if(s1.top() == getMin()) s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
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
