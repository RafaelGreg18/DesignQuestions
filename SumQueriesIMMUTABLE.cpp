//Statement: https://leetcode.com/problems/range-sum-query-immutable/

#include <bits/stdc++.h>
using namespace std;


class NumArray {
public:
    vector<int> pa; //prefix sum array

    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size();i++){
            sum += nums[i];
            this->pa.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return this->pa[right];
        return this->pa[right] - this->pa[left-1];
    }
};

/**
 * NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */