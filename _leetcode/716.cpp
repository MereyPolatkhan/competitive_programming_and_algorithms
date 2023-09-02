// author: @assabiyah

class MaxStack {
public:
    unordered_set<int> removed;
    multiset<pair<int, int>> mset;
    stack<pair<int, int>> stk;
    int id = 0;
    MaxStack() {
        
    }
    
    void push(int x) {
        mset.insert({x, id});
        stk.push({x, id});
        id++;
    }
    
    int pop() {
        while (removed.count(stk.top().second) == 1) {
            stk.pop();
        }   
        pair<int, int> p = stk.top();
        
        removed.insert(p.second);
        stk.pop();
        
        return p.first;
    }
    
    int top() {
        while (removed.count(stk.top().second) == 1) {
            stk.pop();
        }   
        return stk.top().first;    
    }
    
    int peekMax() {
        while (removed.count(mset.rbegin()->second) == 1) {
            mset.erase(prev(mset.end()));
        }
        return mset.rbegin()->first;

    }
    
    int popMax() {
        while (removed.count(mset.rbegin()->second) == 1) {
            mset.erase(prev(mset.end()));
        }
        pair<int, int> p = *mset.rbegin();
        mset.erase(prev(mset.end()));
        removed.insert(p.second);
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

 class MaxStack {
private:
    set<pair<int, int>> stack;
    set<pair<int, int>> values;
    int cnt;

public:
    MaxStack() { cnt = 0; }

    void push(int x) {
        stack.insert({cnt, x});
        values.insert({x, cnt});
        cnt++;
    }

    int pop() {
        pair<int, int> p = *stack.rbegin();
        stack.erase(p);
        values.erase({p.second, p.first});
        return p.second;
    }

    int top() { return stack.rbegin()->second; }

    int peekMax() { return values.rbegin()->first; }

    int popMax() {
        pair<int, int> p = *values.rbegin();
        values.erase(p);
        stack.erase({p.second, p.first});
        return p.first;
    }
};




class MaxStack {
private:
    stack<pair<int, int>> stk;
    priority_queue<pair<int, int>> heap;
    unordered_set<int> removed;
    int cnt;

public:
    MaxStack() { cnt = 0; }

    void push(int x) {
        stk.push({x, cnt});
        heap.push({x, cnt});
        cnt++;
    }

    int pop() {
        while (removed.count(stk.top().second)) {
            stk.pop();
        }
        const pair<int, int> p = stk.top();
        stk.pop();
        removed.insert(p.second);
        return p.first;
    }

    int top() {
        while (removed.count(stk.top().second)) {
            stk.pop();
        }
        return stk.top().first;
    }

    int peekMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        return heap.top().first;
    }

    int popMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        const pair<int, int> p = heap.top();
        heap.pop();
        removed.insert(p.second);
        return p.first;
    }
};


