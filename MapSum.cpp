//Statement: https://leetcode.com/problems/map-sum-pairs/

#include <bits/stdc++.h>
using namespace std;

class MapSum{
public:
    map<string, int> mp;

    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    bool isPrefix(string prefix, string str){
        return str.compare(0, prefix.size(), prefix) == 0;
    }

    int sum(string prefix) {
        int sum = 0;
        for (auto it = mp.lower_bound(prefix); it != mp.end(); it++){
            if (!isPrefix(prefix, it->first)) break;
            else sum += it->second;
        }
        return sum;
    }
};

/**
 * MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */