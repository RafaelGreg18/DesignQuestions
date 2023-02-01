//Statement: https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;
    vector<int> minEl;
    int n;

    MinStack() {
        this->st = stack<int>();
        this->minEl = vector<int>();
        this->n = 0;
    }
    
    void push(int val) {
        this->st.push(val);
        if (n>0) this->minEl.push_back(min(this->minEl[this->n-1], val));
        else this->minEl.push_back(val);
        this->n += 1;
    }
    
    void pop() {
        this->st.pop();
        this->n -= 1;
        this->minEl.pop_back();
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        return this->minEl[this->n-1];
    }
};

/**
 * MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */