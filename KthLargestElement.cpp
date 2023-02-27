//Statement: https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <bits/stdc++.h>
using namespace std;


class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int kth;

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (auto x: nums){
            pq.push(x);
            if (pq.size() > kth) pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > kth) pq.pop();
        return pq.top();
    }
};

/**
 * KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */