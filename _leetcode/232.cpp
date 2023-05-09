class MyQueue {
public:
    int front = 1e9;
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {

    }
    
    void push(int x) {
        if (s1.size() == 0) {
            front = x;
        }
        s1.push(x);
    }
    
    int pop() {
        if (s2.size() == 0) {
            while (s1.size() != 0) {
                int tp = s1.top();
                s1.pop();
                s2.push(tp);
            }
        }
        int tp2 = s2.top();
        s2.pop();
        return tp2;
    }
    
    int peek() {
        if (s2.size() != 0) {
            return s2.top();
        }
        return front != 1e9 ? front : s2.top();
    }
    
    bool empty() {
        return s1.empty() and s2.empty();
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