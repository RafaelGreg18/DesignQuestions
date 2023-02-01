//Statement: https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> queue, aux;

    MyQueue() {
        
    }
    
    void push(int x) {
        aux.push(x);
    }

    void fill(stack<int>& target, stack<int>& src){
        while(!src.empty()){
            target.push(src.top());
            src.pop();
        }
    }
    
    int pop() {
        fill(queue, aux);
        int ans = queue.top();
        queue.pop();
        fill(aux, queue);
        return ans;
    }
    
    int peek() {
        fill(queue,aux);
        int ans = queue.top();
        fill(aux, queue);
        return ans;
    }
    
    bool empty() {
        return aux.size()==0;
    }
};

/**
 * MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */