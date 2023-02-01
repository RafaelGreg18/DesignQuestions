//Statement: https://leetcode.com/problems/snapshot-array/

#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int,int>>> snapshots;
    int n = 0;
    SnapshotArray(int length) {
        snapshots = vector<vector<pair<int,int>>>(length, vector<pair<int,int>>(1,{0,0}));
    }
    
    void set(int index, int val) {
        int lastSnap = snapshots[index].size()-1; 
        if (n == snapshots[index][lastSnap].second){ //
            snapshots[index][lastSnap].first = val;
        } else{
            snapshots[index].push_back(make_pair(val, n));
        }
    }
    
    int snap() {
        n += 1;
        return n-1;
    }
    
    int get(int index, int snap_id) {
        int l = 0, r = snapshots[index].size()-1;
        while (r >= l){
            int mid = (l+r)/2;
            if (snapshots[index][mid].second == snap_id) return snapshots[index][mid].first;
            else if (snapshots[index][mid].second > snap_id) r = mid-1;
            else l = mid+1;
        }
        return snapshots[index][r].first;
    }
};

/**
 * SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */