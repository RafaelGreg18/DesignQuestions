//Statement: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    vector<int> v1,v2;
    map<int,int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto x: nums2){
            mp[x]++;
        }
        v2 = nums2;
        v1 = nums1;
        sort(v1.begin(), v1.end());
    }
    
    void add(int index, int val) {
        mp[v2[index]] -= 1;
        v2[index] += val;
        mp[v2[index]] += 1;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int i = 0 ; i < v1.size(); i++){
            if (v1[i] > tot) break;
            else ans += mp[tot-v1[i]];
        }
        return ans;
    }
};

/**
 * FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */