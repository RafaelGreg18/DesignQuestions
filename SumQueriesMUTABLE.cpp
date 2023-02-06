//Statement: https://leetcode.com/problems/range-sum-query-mutable/

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> arr, tree;

    NumArray(vector<int>& nums) {
        arr = nums;
        tree.resize(4*arr.size()+1);
        buildTree(1, 0, nums.size()-1);
    }

    void buildTree(int pos, int l, int r){
        if (l==r){
            tree[pos] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*pos, l, mid);
        buildTree(2*pos+1, mid+1, r);
        tree[pos] = tree[2*pos] + tree[2*pos+1];
    }

    int sum(int tp, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return tree[tp];
        }
        int tm = (tl + tr) / 2;
        return sum(tp*2, tl, tm, l, min(r, tm))
            + sum(tp*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void updateTree(int tp, int tl, int tr, int index, int val){
        if (tl == tr) tree[tp] = val;
        else{
            int tm = (tl + tr) / 2;
            if (index <= tm)
                updateTree(tp*2, tl, tm, index, val);
            else
                updateTree(tp*2+1, tm+1, tr, index, val);
            tree[tp] = tree[tp*2] + tree[tp*2+1];
        }
    }

    
    
    void update(int index, int val) {
        updateTree(1, 0, arr.size()-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sum(1, 0, arr.size()-1, left, right);
    }
};

/**
 * NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */