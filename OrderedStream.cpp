//Statement: https://leetcode.com/problems/design-an-ordered-stream/

#include <bits/stdc++.h>
using namespace std;

class OrderedStream {
public:
    vector<string> strs;
    int ptr = 0;

    OrderedStream(int n) {
        strs = vector<string>(n , "");
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        strs[idKey-1] = value;
        while(strs[ptr] != "" && ptr < strs.size()){
            ans.push_back(strs[ptr]);
            ptr++;
        }
        return ans;
    }
};

/**
 * OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */